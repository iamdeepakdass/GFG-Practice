//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rev(i,a,b) for(int i=a; i>=b; i--)
#define ll int
typedef vector<int> vi;
class Solution{
  public:
    int getMaxArea(int arr[], int n)
    {
        // Your code here
        ll ans = 0;
        ll curr = 0;
        stack<ll> st;
        // ps and ns arrays to store previous and next smaller element of each element
        vi ps(n);
        vi ns(n);
        
        // store the previous smaller elements of each element
        rep(i,0,n){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ps[i] = (st.empty()) ? (-1) : st.top();
            st.push(i);
        }
        
        // empty the stack for the next iteration
        while(!st.empty()){
            st.pop();
        }
        
        // store the next smaller elements of each element
        rev(i,n-1,0){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ns[i] = (st.empty()) ? (n) : st.top();
            st.push(i);
        }
        
        // now calculate area for each element and update ans accordingly
        rep(i,0,n){
            curr = arr[i];
            curr += arr[i]*(ns[i] - ps[i] - 2);
            ans = max(ans, curr);
        }

        return ans;
    }
    
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        
        int ans = getMaxArea(M[0], m);
        
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(M[i][j] == 1){
                    M[i][j] += M[i-1][j];
                }
            }
            ans = max(ans, getMaxArea(M[i], m));
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends