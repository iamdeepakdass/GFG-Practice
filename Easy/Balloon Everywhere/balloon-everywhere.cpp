//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        
        unordered_map<char, int> mpp;
        int cnt = 0;
        for(int i=0; i<s.size(); i++){
            mpp[s[i]]++;
        }
        
        while(true){
            if(mpp['b'] >= 1 && mpp['a'] >= 1 && mpp['n'] >= 1 && mpp['l'] >= 2 && mpp['o'] >= 2){
                mpp['b']--;
                mpp['a']--;
                mpp['n']--;
                mpp['l'] -= 2;
                mpp['o'] -= 2;
                cnt++;
                
            }
            else break;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends