//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        int n = s.size();
        int ans = 0;

        unordered_map<char, int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
        
        for(int i=n-1; i>=0; i--){
            char ch = s[i];
            if(ch == 'V' && i != 0 && s[i-1] == 'I'){
                ans += 4;
                i--;
            }
            else if(ch == 'X' && i != 0 && s[i-1] == 'I'){
                ans += 9;
                i--;
            }
            else if(ch == 'L' && i != 0 && s[i-1] == 'X'){
                ans += 40;
                i--;
            }
            else if(ch == 'C' && i != 0 && s[i-1] == 'X'){
                ans += 90;
                i--;
            }
            else if(ch == 'D' && i != 0 && s[i-1] == 'C'){
                ans += 400;
                i--;
            }
            else if(ch == 'M' && i != 0 && s[i-1] == 'C'){
                ans += 900;
                i--;
            }
            
            else ans += mpp[ch];
        }   
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends