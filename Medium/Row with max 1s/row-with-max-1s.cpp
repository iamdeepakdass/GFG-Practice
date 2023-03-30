//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    
	    int cnt = 0;
	    int ans = -1;
	    int temp = 0;
	    
	    for(int i=0; i<n; i++){
	        
	        // Since the row is sorted in sorted, then access the elements from end
	        for(int j=m-1; j>=0; j--){
	            // Counting the number of 1's
	            if(arr[i][j] == 1){
	                cnt++;
	            }
	            // if the element is zero the break the loop
	            else{
	                break;
	            }
	        }
	        
	        // if the count of 1's in this row is greater than previous row
	        // then update the temp(no of previous 1s) as cnt
	        if(cnt > temp){
	            temp = cnt;
	            ans = i;
	        }
	        // after traversing current row, update the cnt to 0
	        cnt = 0;
	    }
	    
	    return ans;
	    
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends