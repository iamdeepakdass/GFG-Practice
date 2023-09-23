//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    bool isValid(char ch){
        return ch >= '0' && ch <= '9';
    }
    
    bool isNumericalString(string &s){
        int n = s.size();
        
        if(s[0] == '-'){
            for(int i=1; i<n; i++){
                if(!(isValid(s[i]))) return false;
            }
        }
        else{
            for(int i=0; i<n; i++){
                if(!(isValid(s[i]))) return false;
            }
        }
        
        return true;
    }
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int n = str.size();
        int ans = 0;
        
        if(!isNumericalString(str)) return -1;
        
        if(str[0] == '-'){
            for(int i=1; i<n; i++){
                int num = str[i] - '0';
                ans = ans*10 + num;
            }
            return (-1)*ans;
        }
        else{
            for(int i=0; i<n; i++){
                int num = str[i] - '0';
                ans = ans*10 + num;
            }
            return ans;
        }
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends