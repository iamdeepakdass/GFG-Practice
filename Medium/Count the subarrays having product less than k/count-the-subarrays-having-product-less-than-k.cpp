//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

#define rep(i,a,b) for(int i=a; i<b; i++)
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
            
        int cnt = 0;
        int i = 0, j = 0;
        long long p = 1;
        
        while(j < n){
            p *= a[j];
            
            while(i < n && p >= k){
                p /= a[i];
                i++;
            }
            
            if(p < k){
                cnt += (j-i+1);
            }
            
            j++;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends