//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        bool range(int n){
            return (n >= 0 && n <= 255);
        }
        
        bool isValid(char c){
            return (c >= '0' && c <= '9');
        }
        
        int toInt(string s){
            int ans = 0;
            int k = 0;
            
            for(int i=s.size() - 1; i >= 0; i--){
                int num = s[i] - '0';
                ans += (num*pow(10,k++));
            }
            
            return ans;
        }
        
        int isValid(string s) {
            // code here
            if(s[0] == '0' && s[1] == '0') return 0;
            int n = s.size();
            string temp = "";
            int dotCnt = 0;
            for(int i=0; i<n; i++){
                if(s[i] != '.' && !(isValid(s[i])))return 0;
            }
            
            for(int i=0; i<n; i++){
                if(s[i] == '.'){
                    dotCnt++;
                    int num = toInt(temp);
                    if(!range(num))return 0;
                    else if(temp.empty())return 0;
                    else if((temp[0] == '0' && temp.size() > 1)) return 0;
                    else{
                        temp.clear();
                    }
                }    
                else temp += s[i];
            }
            
            if((temp[0] == '0' && temp.size() > 1)) return 0;
            
            if(dotCnt != 3)return 0;
            return 1;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends