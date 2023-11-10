//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here 
        int n = s.size();
        
        string ans = "";
        
        for(int j=0; j<=n; j++){
            ans.push_back('1' + j);
        }
        int cnt = 0;
        
        for(int j=0; j<n; j++){
            if(s[j] == 'D') cnt++;
            
            else{
                reverse(ans.begin() + j - cnt, ans.begin() + j + 1);
                cnt =  0;
            }
        }
        
        reverse(ans.begin() + n - cnt, ans.begin() + n + 1);
        
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends