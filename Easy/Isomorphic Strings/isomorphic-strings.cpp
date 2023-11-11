//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s, string t)
    {
        
        // Your code here
        int n = s.size(), m = t.size();
        if(m != n) return false;
        
        unordered_map<char, int> mpp;
        
        for(int i=0; i<n; i++){
            if(mpp.find(s[i]) != mpp.end()){
                if(mpp[s[i]] != t[i]) return false;
            }
            else mpp[s[i]] = t[i];
        }
        
        
        unordered_map<char, int> umap;
        
        for(int i=0; i<n; i++){
            
            if(umap.find(t[i]) != umap.end()){
                if(umap[t[i]] != s[i]) return false;
            }
            else umap[t[i]] = s[i];
        }
        
        
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends