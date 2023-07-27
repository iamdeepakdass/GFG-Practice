//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

const int Mod = 1e9 + 7;

class Solution {
  public:
    int fibbCalc(int n, vector<int> &dp){
        if(dp[n] == -1) {
            int ans;
            if(n == 0 || n == 1){
                ans = n;
            }
            else ans = fibbCalc(n-1, dp) + fibbCalc(n-2, dp);
            dp[n] = ans%Mod;
        }
        
        return dp[n];
    }
    
    int nthFibonacci(int n){
        // code here
        vector<int> dp(n+10, -1);
        return fibbCalc(n, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends