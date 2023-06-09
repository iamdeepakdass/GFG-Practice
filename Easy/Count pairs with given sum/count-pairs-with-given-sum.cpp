//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        
        map<int, int> mpp;
        
        for(int i=0; i<n; i++){
            mpp[arr[i]]++;
        }
        
        int ans = 0;
        int temp = 0;
        int more = 0;
        
        for(int i=0; i<n; i++){
            temp = arr[i];
            more = k-temp;
            if(mpp.find(more) != mpp.end()){
                ans += mpp[more];
            }
            
            if(more == arr[i]){
                ans--;
            }
        }
        
        return ans/2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends