//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define rep(i, a, b) for (int i = a; i < b; i++)
#define ll long long

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int k = 0;
	    
	    rep(i,0, n){
	        k += arr[i];
	    }
	    //cout<<k<<" k\n";
	    int ans = INT_MAX;
	    vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));
	    
	    rep(i,0,n+1){
	        dp[i][0] = true;
	    }
	    
	    rep(i,1,n+1){
	        rep(j,1,k+1){
	            if(arr[i-1] <= j){
	                dp[i][j] = dp[i-1][j - arr[i-1]] | dp[i-1][j];
	            }
	            else dp[i][j] = dp[i-1][j];
	        }
	    }
	    
	   // vector<int> temp;
	    
	   // rep(i, 0, k/2){
	   //     if(dp[n][i]){
	   //         temp.push_back(i);
	   //     }
	   // }
	    
	   // rep(i,0,temp.size()){
	   //     cout<<temp[i]<<" ";
	   // }
	    
	   // cout<<"\n";
	    
	   // rep(i,0, temp.size()){
	   //     ans = min(ans, abs(k-2*temp[i]));
	   // }
	   
	   for(int i=0; i<= k/2; i++){
	       if(dp[n][i]){
	           ans = min(ans, abs(k-2*i));
	       }
	   }
	    
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends