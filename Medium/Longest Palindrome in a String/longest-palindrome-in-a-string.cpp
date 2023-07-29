//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string longestPalin (string s) {
        // code here
        string t = s;
        reverse(t.begin(), t.end());
        int n = t.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int x,y;
        int maxi = 0;
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(dp[i][j] > maxi){
                        int tIdx = n-j;
                        if(tIdx + dp[i][j] - 1 == i-1){
                            x = i;
                            y = j;
                            maxi = dp[i][j];
                        }
                    }
                }
                else dp[i][j] = 0;
            }
        }
        //cout<<maxi<<" maxi\n";

        // cout<<x<<" x "<<y<<" y \n";

        int i = x, j = y;
        string ans = "";
        
        while(i > 0 && j > 0 && dp[i][j] > 0){
            ans += s[i-1];
            i--;
            j--;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends