//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
#define lli long long int
class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        lli sum = 0;
        lli cnt = 0;
        
        unordered_map<lli, int> mpp;
        mpp[0] = 1;
        
        for(int i=0; i<n; i++){
            
            sum += arr[i];
            
            if(mpp.find(sum) != mpp.end()){
                cnt += mpp[sum];
            }
            
            mpp[sum]++;
            
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends