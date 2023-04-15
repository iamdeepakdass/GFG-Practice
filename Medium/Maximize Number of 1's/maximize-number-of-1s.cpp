//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        int countZeroes = 0;
        int res = INT_MIN;
        
        int right = 0;
        int left = 0;
        
        while(right < n){
            // if element is zero then increase the count
            if(arr[right] == 0){
                countZeroes++;
            }
            
            // if the count is more than m then decrease the size of the window
            while(countZeroes > m){
                // if the element is zero then exclude it from the window i.e. decrease the count
                if(arr[left] == 0){
                    countZeroes--;
                }
                // we will move the left pointer in order to reduce the window
                left++;
            }
            
            // update the result by max size of the window
            res = max(res, right-left+1);
            // move the right pointer ahead
            right++;
        }
        
        return res;
    }  
  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends