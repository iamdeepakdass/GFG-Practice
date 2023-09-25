//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
#define ll long long 
class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
        // Your code goes here
        vector<vector<int>> ans;
        
        int n = arr.size();
        if(n <= 3) return ans;
        
        sort(begin(arr), end(arr));
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                ll reqd = (ll)target - (ll)arr[i] - (ll)arr[j];
                
                int l = j+1, r = n-1;
                
                while(l < r){
                    ll sum = (ll)arr[l] + (ll)arr[r];
                    
                    if(sum < reqd) l++;
                    else if(sum > reqd) r--;
                    else{
                        vector<int> temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[l]);
                        temp.push_back(arr[r]);
                        
                        ans.push_back(temp);
                        
                        while(l < r && arr[l] == temp[2]) l++;
                        while(l < r && arr[r] == temp[3]) r--;
                    }
                }
                while(j+1 < n && arr[j+1] == arr[j]) j++;
            }
            
            while(i+1 < n && arr[i+1] == arr[i]) i++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends