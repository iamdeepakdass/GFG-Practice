//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<int> DistinctSum(vector<int>nums){
	    // Code here
	    int n = nums.size();
	    int sum = 0;
	    for(int i=0; i<n; i++) sum += nums[i];
	    
	    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
	    
	    for(int i=1; i<n+1; i++){
	        for(int j=1; j<sum+1; j++){
	            if(nums[i-1] <= j){
	                dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]], dp[i-1][j]);
	            }
	            else dp[i][j] = dp[i-1][j];
	        }
	    } 
	    
	    unordered_map<int, int> mpp;
	    vector<int> ans;
	    for(int i=0; i<n+1; i++){
	        for(int j=0; j<sum+1; j++){
	            if(mpp.find(dp[i][j]) == mpp.end()){
	                ans.push_back(dp[i][j]);
	                mpp[dp[i][j]]++;
	            }
	            //cout<<dp[i][j]<<" ";
	        }
	        //cout<<"\n";
	    }
	    
	    sort(ans.begin(), ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends