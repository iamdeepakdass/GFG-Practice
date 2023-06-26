//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        ll ans = 0;
        ll curr = 0;
        stack<ll> st;
        vector<int>ps(n);
        st.push(0);
        
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ps[i] = (st.empty()) ? (-1) : st.top();
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        vector<int>ns(n);
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ns[i] = (st.empty()) ? (n) : st.top();
            st.push(i);
        }
        
        // //reverse(ns.begin(), ns.end());
        // for(int i=0; i<n; i++){
        //     cout<<ns[i]<<" ";
        // }
        
        for(int i=0; i<n; i++){
            curr = arr[i];
            curr += ((i-ps[i]-1)*arr[i]);
            (curr += (ns[i]-i-1)*arr[i]);
            
            ans = max(ans, curr);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends