//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <bits/stdc++.h>
class Solution
{
	public:
	    void solve(int ind, int n, set<string> &ans, string &s){
	        
	        if(ind == n){
	            ans.insert(s);
	            return;
	        }
	        
	        for(int i=ind; i<n; i++){
	           // if(i != ind && s[i] == s[i-1]){
	           //     continue;
	           // }
	            swap(s[ind], s[i]);
	            solve(ind+1, n, ans, s);
	            swap(s[ind], s[i]);
	        }
	    }
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string> ans;
		    int n = S.size();
		    
		    solve(0, n, ans, S);
		    //sort(ans.begin(), ans.end());
		    
		    vector<string>anss(ans.begin(), ans.end());  
		    return anss;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends