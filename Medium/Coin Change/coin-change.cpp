//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
#define rep(i, a, b) for (int i = a; i < b; i++)

class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<ll>> dp(N+1,vector<ll>(sum+1,0));
        rep(i,0,N+1){
            dp[i][0] = 1;
        }
        
        rep(i,1,N+1){
            rep(j,1,sum+1){
                if(coins[i-1] <= j){
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[N][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends