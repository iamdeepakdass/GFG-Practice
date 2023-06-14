//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std; 

// } Driver Code Ends

class Solution{
    public:
    bool isSubSequence(string A, string B) 
    {
        // code here
        int i = 0;
        int j = 0;
        int n = A.size();
        int m = B.size();
        
        if(n>m){
            return false;
        }
        
        while(i<n && j<m){
            if(A[i] == B[j]){
                j++;
                i++;
            }
            else{
                j++;
            }
        }
        
        return (i==n);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;  
        Solution ob;
        if(ob.isSubSequence(A,B))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0; 
} 

// } Driver Code Ends