//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int oldMax = -1, newMax = 0 + arr[0];
        int jumps = 0, curr = 0;
        
        while(oldMax != newMax){
            oldMax = newMax;
            if(oldMax >= n-1) return jumps + 1;
            for(int j = curr+1; j <= oldMax; j++){
                newMax = max(newMax, j + arr[j]);
            }
            curr = oldMax;
            jumps++;
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends