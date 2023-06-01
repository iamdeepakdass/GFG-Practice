//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        
        unordered_map<int, int> mpp;
        
        for(int i=0; i<n; i++){
            mpp[arr[i]]++;
        }
        
        int ans = INT_MIN;
        int minFreq = INT_MAX;
        
        for(auto it: mpp){
            minFreq = min(it.second, minFreq);
        }
        
        for(auto it: mpp){
            if(it.second == minFreq){
                if(it.first > ans){
                    ans = it.first;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends