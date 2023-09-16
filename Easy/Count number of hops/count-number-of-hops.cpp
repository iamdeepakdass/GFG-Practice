//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long

class Solution
{
    public:
    int MOD = 1e9 + 7;
    
    ll solve(int n, vector<ll> &dp){
        if(n < 0) return 0;
        if(n == 0 || n == 1) return 1;
        if(n == 2) return 2;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = (solve(n-1, dp)%MOD + solve(n-2, dp)%MOD + solve(n-3, dp)%MOD)%MOD;
    }
    
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        // your code here
        vector<ll> dp(n+1, -1);
        return solve(n, dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends