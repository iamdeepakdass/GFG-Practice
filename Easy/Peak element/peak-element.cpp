//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
        int left = 0;
        int right = n - 1;
        int ans = -1;
        
        // Considering edge cases
        if((arr[0] > arr[1]) || n == 0){
            return 0;
        }
        
        if(arr[n-1] > arr[n-2]){
            return n-1;
        }
        
        // Applying BS on the 1 to n-1 elements
        while(left <= right){
            
            int mid = left + (right - left)/2;
            
            // condition for the peak element
            if((arr[mid] >= arr[mid-1]) && (arr[mid] >= arr[mid+1])){
                return mid;
            }
            
            else if(arr[mid-1] < arr[mid]){
                left = mid + 1;
            }
            
            else{
                right = mid - 1;
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			tmp[i] = a[i];
		}
		bool f=0;
		Solution ob;
		
		int A = ob. peakElement(tmp,n);
		
		if(A<0 and A>=n)
		    cout<<0<<endl;
		else
		{
    		if(n==1 and A==0)
    		    f=1;
    		else if(A==0 and a[0]>=a[1])
    		    f=1;
    		else if(A==n-1 and a[n-1]>=a[n-2])
    		    f=1;
    		else if(a[A]>=a[A+1] and a[A]>= a[A-1])
    		    f=1;
    		else
    		    f=0;
    		cout<<f<<endl;
		}
		
	}

	return 0;
}
// } Driver Code Ends