//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    const int mod = 1e9+7;
    vector<ll> nthRowOfPascalTriangle(int n) {
        // // code here
        vector<vector<ll>> arr(n,vector<ll>(n,0));
        
        arr[0][0] = 1;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                if(j == 0 || i == j){
                    arr[i][j] = 1;
                }
                else{
                    arr[i][j] = (arr[i-1][j-1] + arr[i-1][j])%mod;
                }
            }
        }
        
        vector<ll> ans;
        for(int i=0; i<n; i++){
            ans.push_back(arr[n-1][i]);
        }
        return ans;
        
        // vector<ll>res;
        // int ans = 1 ;
        
        // res.push_back(1) ;
        // for(int i=1;i<n;i++){
        //   ans = (ans*(n-i))%mod ;
        //   ans = (ans/i)%mod ;
        //   res.push_back(ans) ;
        // }
        
        // return res ;
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends