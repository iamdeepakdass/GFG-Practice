//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    
        ll ans = INT_MAX;
        sort(a.begin(), a.end());
        
        ll i = m-1;
        while(i < n){
            ll x = a[i] - a[i-m+1];
            ans = min(ans, x);
            i++;
        }
        
        return ans;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends