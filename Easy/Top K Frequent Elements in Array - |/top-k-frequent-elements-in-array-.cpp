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
        
        // store frequencies of elements in a map
        map<int, int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        
        // make a vector of pairs and store the value, frequency pair
        vector<pair<int,int>> temp;
        for(auto it: mpp){
            temp.push_back({it.first, it.second});
        }
        
        // swap pairs and then sort according to the frequencies
        for(int i=0; i<temp.size(); i++){
            swap(temp[i].first, temp[i].second);
        }
        sort(temp.begin(), temp.end());
        
        int len = temp.size() - 1;
        vector<int> ans;
        // store values which has maximum frequecies
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