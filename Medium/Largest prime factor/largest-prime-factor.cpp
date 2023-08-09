//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

#define lli long long int

class Solution{
public: 
    long long int largestPrimeFactor(int N){
        // code here
        lli ans = 1;
        
        for(int i=2; i*i <= (N); i++){
            while(N%i == 0){
                ans = i;
                N /= i;
            }
            //else continue;
        }
        
        if(N > 1) ans = N;
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends