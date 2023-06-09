//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        // map<int, int>mpA;
        // map<int, int>mpB;
        // for(int i=0; i<n; i++){
        //     mpA[A[i]] = i;
        // }
        // for(int i=0; i<m; i++){
        //     mpB[B[i]] = i;
        // }
        sort(A, A+n);
        sort(B, B+m);
        int sumA = 0;
        int sumB = 0;
        
        for(int i=0; i<n; i++){
            sumA += A[i];
        }
        for(int i=0; i<m; i++){
            sumB += B[i];
        }
        
        int i=0, j=0;
        while(i<n && j<m){
            int newSumA = sumA - A[i] + B[j];
            int newSumB = sumB - B[j] + A[i];
            if(newSumA == newSumB){
                return 1;
            }
            else if(newSumA < newSumB){
                j++;
            }
            else{
                i++;
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