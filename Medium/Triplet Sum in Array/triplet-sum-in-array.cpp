//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        bool ans = false;
        
        sort(A, A+n);
        
        for(int i=0; i<n; i++){
            
            if(i > 0 && A[i] == A[i+1]){
                continue;
            }
            int j = i+1;
            int k = n-1;
            
            while(j < k){
                int sum = A[i] + A[j] + A[k];
                
                if(sum < X){
                    j++;
                }
                else if(sum > X){
                    k--;
                }
                
                else{
                    ans = true;
                    break;
                }
            }
        }
        
        return ans;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends