//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

#define rep(i, a, b) for (int i = a; i < b; i++)

class Solution{   
public:
    // bool solver(vector<int>arr, int sum, vector<vector<bool>> &dp){
    //     int n = arr.size();
        
    //     rep(i, 0, n+1){
    //         rep(j, 0, sum+1){
    //             if(i == 0) dp[i][j] = false;
    //             if(j == 0) dp[i][j] = true;
    //         }
    //     }
        
    //     rep(i, 1, n+1){
    //         rep(j, 1, sum+1){
    //             if(arr[i-1] <= j){
    //                 dp[i][j] = (dp[i][j - arr[i-1]]) | dp[i-1][j]; 
    //             }
    //             else dp[i][j] = dp[i-1][j];
    //         }
    //     }
        
    //     return dp[n][sum];
    // }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        
        rep(i, 0, n+1){
            rep(j, 0, sum+1){
                if(i == 0) dp[i][j] = false;
                if(j == 0) dp[i][j] = true;
            }
        }
        
        rep(i, 1, n+1){
            rep(j, 1, sum+1){
                if(arr[i-1] <= j){
                    dp[i][j] = (dp[i-1][j - arr[i-1]]) || dp[i-1][j]; 
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends