//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        vector<int> ans;
        stack<int> st;
        st.push(-1);
        
        for(int i=0; i<n; i++){
            int curr = a[i];
            if(st.top() < curr){
                ans.push_back(st.top());
                st.push(curr);
            }
            else{
                
                while(st.top()>=curr && !st.empty()){
                    st.pop();
                }
                
                ans.push_back(st.top());
                st.push(curr);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends