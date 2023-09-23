//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    //code here
    string ans = "";
    int n = s.size();
    vector<int> freq(26,0);
    
    for(int i=0; i<n; i++){
        if(freq[s[i] - 'a'] > 0){
            ans += s[i];
            return ans;
        }
        freq[s[i] - 'a']++;
    }
    return "-1";
}