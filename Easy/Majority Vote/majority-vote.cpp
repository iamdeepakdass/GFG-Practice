//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
        
        vector<int> ans;
        int count = 0;
        
        map<int, int> mpp;
        
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        
        for(auto x: mpp){
            if(x.second>(n/3)){
                ans.push_back(x.first);
            }
        }
        
        if(ans.empty()) return {-1};
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends