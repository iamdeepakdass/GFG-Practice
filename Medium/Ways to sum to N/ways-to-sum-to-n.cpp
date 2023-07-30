//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution
{
  public:
    int mod = 1e9 + 7;
    
    int helper(int arr[], int n, int sum, vector<int> &dp){
        if(sum == 0) return 1;
        if(sum < 0) return 0;
        
        if(dp[sum] != -1) return dp[sum];
        
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = (ans + (helper(arr, n, sum-arr[i], dp))%mod)%mod;
        }
        
        return dp[sum] = ans%mod;
    }
    // function to count the total  
    // number of ways to sum up to 'N' 
    int countWays(int arr[], int m, int N) 
    { 
        vector<int> dp(N + 1, -1);
        
        return helper(arr, m, N, dp);
    }

    
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int m,n ;
	        cin>>m>>n;
	        int arr[m];
	        for(int i = 0;i<m;i++)
	            cin>>arr[i];
	        Solution ob;     
	        cout<<ob.countWays(arr,m,n)<<endl;
	    }
}
// } Driver Code Ends