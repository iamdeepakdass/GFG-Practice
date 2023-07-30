//{ Driver Code Starts
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
 
int maxSubsequenceSubstring(string x, string y, int n, int m);
 
// Driver Program
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        string x,y;
        cin>>n>>m;
        cin>>x>>y;
        cout<<maxSubsequenceSubstring(x,y,n,m)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

#define rep(i, a, b) for (int i = a; i < b; i++)

int maxSubsequenceSubstring(string X, string Y, int N, int M){
    //code
    
        vector<vector<int>>dp(M+1,vector<int>(N+1,0));
        int maxlen=0;
        for(int i=1;i<=M;i++){
            for(int j=1;j<=N;j++){
                if(Y[i-1]==X[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    maxlen=max(maxlen,dp[i][j]);
                }
            else{
                dp[i][j]=dp[i][j-1];
                }
               
            }
        }
        return maxlen;
    
}