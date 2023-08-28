//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isValid(char c){
        return (c >= 'A' && c <= 'Z');
    }
    
    bool check(string &word, string &pat){
        int j = 0;
        int n = word.size();
        int m = pat.size();
        
        string temp = "";
        
        for(int i=0; i<n; i++){
            if(isValid(word[i]))temp += word[i];
        }
        
        return pat == temp.substr(0,m);
    }
    
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        // code here
        int n = Dictionary.size();
        
        vector<string> ans;
        
        for(int i=0; i<n; i++){
            if(check(Dictionary[i], Pattern)){
                ans.push_back(Dictionary[i]);
            }
        }
        
        if(ans.empty()) return {"-1"};
        return ans;
        
        // if(!ans.empty()){
        //     sort(ans.begin(), ans.end());
        //     for(int i=0; i<ans.size(); i++){
        //         cout<<ans[i] <<" ";
        //     }
        // }
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends