//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        
        int n = s.size();
        int l = 0, r;
        
        for(int i=0; i<n; i++){
            if(s[i] == '.'){
                reverse(s.begin()+l, s.begin() + r + 1);
                l = i+1;
            }   
            else r = i;
        }
        
        reverse(s.begin()+l, s.begin() + r + 1);
        
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends