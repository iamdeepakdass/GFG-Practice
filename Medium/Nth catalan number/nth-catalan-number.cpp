//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int mod = 1e9+7;
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        vector<long> dp(n+1);
        dp[0] = 1L;
        dp[1] = 1L;
        
        for(int i=2; i<=n; i++){
            for(int j=0; j<i; j++){
                dp[i] = (dp[i] + dp[j] * dp[i-j-1])%mod;
            }
        }
        
        return (int)dp[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends