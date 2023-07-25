//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long

class Solution{

	public:
	int minCoins(int coins[], int n, int sum) 
	{ 
	    // Your code goes here
	    int INF = INT_MAX - 1;
	    
	    vector<vector<ll>> dp(n+1, vector<ll>(sum+1, 0));
	    
	    //Intialise first row with 0s
	    for(int i = 0; i <= sum; i++){
	        dp[0][i] = INF;
	    }
	    
	    //Intialise first column with 0s
	    for(int i = 1; i <= n; i++){
	        dp[i][0] = 0;
	    }
	    
	    //Intialise second row with condition of sum can be obtained or not
	    for(int j = 1; j< sum+1; j++){
	        if(j%coins[0] == 0){
	            dp[1][j] = j/coins[0];
	        }
	        else dp[1][j] = INF;
	    }  
	    
	    
	    for(int i=2; i<n+1; i++){
	        for(int j=1; j<sum+1; j++){
	            if(coins[i-1] <= j){
	                dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
	            }
	            else dp[i][j] = dp[i-1][j];
	        }
	    }
	    
	    if(dp[n][sum] == INF)return -1;
	    
	    return dp[n][sum];
	} 
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends