//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
#include<string>
class Solution {
  public:
    string findSum(string X, string Y) {
        
        // Refine strings X and Y;
        string refinedX = "";
        string refinedY = "";
        
        int i = 0, j = 0;
        
        while(i < X.size()){
            if(X[i] == '0'){
                i++;
            }
            else break;
        }
        
        X = X.substr(i,X.size()-i);
        
        while(j < Y.size()){
            if(Y[j] == '0'){
                j++;
            }
            else break;
        }
        
        Y = Y.substr(j,Y.size()-j);
        
        if(X == "" && Y == ""){
            return "0";
        }
        
        i = X.size() - 1;
        j = Y.size() - 1;
        
        int carry = 0;
        string ans = "";
        
        while(i >= 0 || j >= 0 || carry){
            int sum = 0;
            if(i >= 0){
                int dig1 = X[i] - '0';
                sum += dig1;
                i--;
            }
            if(j >= 0){
                int dig2 = Y[j] - '0';
                sum += dig2;
                j--;
            }
            
            sum += carry;
            ans += to_string(sum%10);
            carry = sum/10;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends