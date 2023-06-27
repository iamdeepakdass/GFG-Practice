//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool isMatching(char a, char b){
        return ((a == '(' && b == ')') ||
                (a == '{' && b == '}') || 
                (a == '[' && b == ']'));
    }
    
    bool ispar(string x)
    {
        // Your code here
        
        stack<char> st;
        
        for(int i=0; i<x.size(); i++){
            
            char ch = x[i];
            
            // if opening bracket then push into stack
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            
            else{
                // if closing brackets
                if(!st.empty()){
                    char temp = st.top();
                    
                    // if((ch == ')' && temp == '(')
                    // || (ch == '}' && temp == '{') 
                    // || (ch == ']' && temp == '[')){
                    //     st.pop();
                    // }
                    // else{
                    //     return false;
                    // }
                    if(isMatching(temp,ch)){
                        st.pop();
                    }
                    else return false;
                }
                else{
                    return false;
                }
            }
        }
        
        // if(st.empty()){
        //     return true;
        // }
        
        // else{
        //     return false;
        // }
        return st.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends