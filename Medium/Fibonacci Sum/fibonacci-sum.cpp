//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define lli long long int

class Solution{
public:
    long long int fibSum(long long int N){
        
        if(N<3) return N;
        
        lli sum = 2;
        lli f0 = 1, f1 = 1;
        lli mod = 1e9+7;
        
        for(int i=3; i<=N; i++){
            lli next = (f1 + f0)%mod;
            sum = (sum + next)%mod;
            f0 = f1;
            f1 = next;
        }
        
        return sum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends