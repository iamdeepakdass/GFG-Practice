//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    
    bool knows(vector<vector<int> >& M,int A, int B, int n){
        return M[A][B] == 1 ? true : false;
    }
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        
        for(int i=0; i<n; i++){
            st.push(i);
        }
        
        while(st.size() > 1){
            int A = st.top();
            st.pop();
            int B = st.top();
            st.pop();
            
            if(knows(M,A,B,n)){
                st.push(B);
            }
            else{
                st.push(A);
            }
        }
        
        int ans = st.top();
        int countZero = 0;
        
        for(int i=0; i<n; i++){
            if(M[ans][i] == 0){
                countZero++;
            }
        }
        if(countZero != n){
            return -1;
        }
        
        int countOne = 0;
        for(int i=0; i<n; i++){
            if(M[i][ans] == 1){
                countOne++;
            }
        }
        
        if(countOne != n-1){
            return -1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends