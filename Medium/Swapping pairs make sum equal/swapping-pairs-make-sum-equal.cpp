//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        map<int, int>mpA;
        map<int, int>mpB;
        for(int i=0; i<n; i++){
            mpA[A[i]] = i;
        }
        for(int i=0; i<m; i++){
            mpB[B[i]] = i;
        }
        
        int sumA = 0;
        int sumB = 0;
        
        for(int i=0; i<n; i++){
            sumA += A[i];
        }
        for(int i=0; i<m; i++){
            sumB += B[i];
        }
        
        int total = sumA + sumB;
        if(total&1){
            return -1;
        }
        else{
            int reqdA = total/2 - sumA;
            int reqdB = total/2 - sumB;
            for(auto it: mpA){
                int temp = sumA - it.first;
                int reqd = total/2 - temp;
                if(mpB.find(reqd) != mpB.end()){
                    return 1;
                    break;
                }
            }
        }
        
        return -1;
	}
 

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends