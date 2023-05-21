//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int i=0; 
        int j = 0;
        int sum = arr[0];
        if(sum > x){
            return 1;
        }
        
        int mini = n + 1;
        
        while(i<n && j<n){
            
            if(sum <= x){
                i++;
                sum += arr[i];
            }
            
            else if( sum > x){
                sum -= arr[j];
                mini = min(mini, i-j+1);
                j++;
            }
        }
        
        return mini;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends