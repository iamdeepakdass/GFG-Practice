//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        stack<int> st;
        string ans = "";
        for(int i=S.size()-1; i>=0; i--){
            if(S[i] != '.'){
                st.push(S[i]);
            }
            else{
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
                ans = ans+ ".";
            }
        }
        
        for(int i=0; i<S.size(); i++){
            if(S[i] == '.'){
                break;
            }
            
            else{
                ans+=S[i];
            }
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends