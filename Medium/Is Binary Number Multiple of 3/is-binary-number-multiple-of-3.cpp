//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	   // int i = 0;
	    
	   // while(i < s.size()){
	   //     if(s[i] == '0'){
	   //         i++;
	   //     }
	   //     else break;
	   // }
	    
	   // s = s.substr(i, s.size() - i);
	    int i = s.size() - 1;
	    
	    long long k = 1;
	    long long int ans = 0;
	    
	    while(i >= 0){
	        int digit = s[i] - '0';
	        if(digit == 1){
	            ans += digit*(k);
	            ans %= 3;
	        }
	        k = (k*2)%3;
	        i--;
	    }
	    
	   // int sum = 0;
	    
	   // while(ans){
	   //     sum += (ans%10);
	   //     ans /= 10;
	   // }
	    
	    return (ans== 0) ? 1 : 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends