//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void solve(int ind, vector<int> &arr, vector<vector<int>> &ans){
        
        if(ind >= arr.size()){
            ans.push_back(arr);
            return;
        }    
        
        unordered_set<int> st;
        
        for(int i=ind; i<arr.size(); i++){
            if(st.find(arr[i]) != st.end()){
                continue;
            }    
            st.insert(arr[i]);
            swap(arr[i], arr[ind]);
            solve(ind+1, arr, ans);
            swap(arr[i], arr[ind]);
        }
        
    }
    
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
        // code here
        vector<vector<int>>ans;
        solve(0, arr, ans);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends