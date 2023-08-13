//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int fib(int n){
        //code here
        int mod = 1e9 + 7;
        if(n < 2) return n;
        int first = 1;
        int second = 1;
        
        for(int i=2; i<n; i++){
            int next = (first + second)%10;
            first = second;
            second = next;
        }
        
        return second%10;
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
        cout << ob.fib(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends