//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int Count(string &s, int k){
        int i = 0, j = 0;
        
        int n = s.size();
        vector<int> freq(26,0);
        int distinct = 0;
        long long int ans = 0;
        
        while(j < n){
            freq[s[j] - 'a']++;
            
            // Distinct character
            if(freq[s[j] - 'a'] == 1) distinct++;
            
            // Decreasing window size
            while(distinct > k){
                freq[s[i] - 'a']--;
                if(freq[s[i] - 'a'] == 0) distinct--;
                i++;
            }
            j++;
            ans += (j - i + 1);
        }
        return ans;
    }
    long long int substrCount(string s, int k) {
    	//code here.
    	return Count(s,k) - Count(s, k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends