//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        
        int missing = 0;
        int repeat = 0;
        
        vector<int> temp (n+1, 0);
        
        for(int i=0; i<n; i++){
            temp[arr[i]]++;
        }
        
        for(int i=0; i<=n; i++){
            if(temp[i] == 0){
                missing = i;
            }
            if(temp[i] == 2){
                repeat = i;
            }
        }
        
        int ans[2] = {0};
        
        ans[1] = missing;
        ans[0] = repeat;
        
        int *aans = ans;
        
        return aans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends