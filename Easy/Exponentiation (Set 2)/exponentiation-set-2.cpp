//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
#define mod 1000000007
class Solution{   
public:
    long long int power(int a, long long int b) { 
        //complete the function here
        
        if(a == 0){
            return 0;
        }
        if(b == 0){
            return 1;
        }
        
        if(!(b&1)){
            long long ans = power(a,b/2);
            return (ans%mod * ans%mod)%mod;
        }
        else{
            long long ans = power(a,(b-1)/2);
            return (a%mod * ans%mod * ans%mod)%mod;
        }
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        long long b;
        cin >> a >> b;
        Solution ob;
        cout << ob.power(a, b) << endl;
    
    }
    return 0; 
} 



// } Driver Code Ends