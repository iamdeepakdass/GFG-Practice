//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    long long int mod =  M;
		    if(x == 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        
        if(!(n&1)){
            long long ans = PowMod(x,n/2,mod);
            return (ans%mod * ans%mod)%mod;
        }
        else{
            long long ans = PowMod(x,(n-1)/2,mod);
            return (x%mod * ans%mod * ans%mod)%mod;
        }
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends