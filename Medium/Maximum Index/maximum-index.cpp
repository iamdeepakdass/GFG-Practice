//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        // Your code here
        int n = N;
        vector<int> Lmin(n);
        vector<int> Rmax(n);
        
        Lmin[0] = A[0];
        for(int i=1; i<n; i++){
            Lmin[i] = min(A[i], Lmin[i-1]);
        }
        
        Rmax[n-1] = A[n-1];
        
        for(int i=n-2; i>=0; i--){
            Rmax[i] = max(A[i], Rmax[i+1]);
        }
        
        int l = 0, r = 0;
        int ans = INT_MIN;
        
        while(l < n && r < n){
            if(Lmin[l] <= Rmax[r]){
                ans = max(ans, (r-l));
                r++;
            }    
            else l++;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends