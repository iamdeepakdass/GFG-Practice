//{ Driver Code Starts
#include <bits/stdc++.h>


using namespace std;




// } Driver Code Ends

class Solution{
  public:
    int Countpair(int arr[], int n, int sum){
        
        // Complete the function
    
        sort(arr, arr+n);
        
        // for(int i=0; i<n; i++){
        //     cout<<arr[i] << " ";
        // }
        // cout<<"\n";
        
        int i = 0, cnt = 0; 
        int j = n-1;
        
        while(i < j){
            int s = arr[i] + arr[j];
            if(s > sum){
                j--;
            }
            else if(s < sum){
                i++;
            }
            else{
                cnt++;
                i++;
                j--;
            }
        }
        
        if(cnt == 0){
            return -1;
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
        cin>>n;
        int arr[n+1];
        
        for(int i=0;i<n;i++)
        cin>>arr[i];

        int sum;
        cin>>sum;
        Solution obj;
        cout << obj.Countpair(arr, n, sum) << endl;
        
    }
	return 0;
}

// } Driver Code Ends