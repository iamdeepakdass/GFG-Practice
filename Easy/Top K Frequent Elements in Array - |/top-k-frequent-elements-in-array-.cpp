//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <iostream>
#include <map>
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        int n = nums.size();
        
        map<int, int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        
        vector<pair<int,int>> temp;
        for(auto it: mpp){
            temp.push_back({it.first, it.second});
        }
        
        for(int i=0; i<temp.size(); i++){
            swap(temp[i].first, temp[i].second);
        }
        
        sort(temp.begin(), temp.end());
        int len = temp.size() - 1;
        vector<int> ans;
        while(k--){
            ans.push_back(temp[len--].second);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends