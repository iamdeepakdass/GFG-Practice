//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define rep(i, a, b) for (int i = a; i < b; i++)

class Solution{
public:
    bool isSubsetSum(int arr[], int n, int sum){
        
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        
        // Mark all the first column elements as TRUE
        rep(i,0,n+1) dp[i][0] = true;
        
        rep(i, 1, n+1){
            rep(j, 1, sum+1){
                if(arr[i-1] <= j){
                    // max analogy from 0-1 knapsack, here we use ||
                    dp[i][j] = (dp[i-1][j - arr[i-1]]) || dp[i-1][j]; 
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        long long sum = 0;
        int n = N;
        rep(i,0,n){
            sum += arr[i];
        }
        if(sum&1) return 0;
        
        else{
            if(isSubsetSum(arr, n, sum/2)) return true;
            else return false;
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends