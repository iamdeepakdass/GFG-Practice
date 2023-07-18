//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int arr[], int N, int X)
    {
        // code here
        sort(arr, arr+N);
        int ans = -1;
        int minDiff = INT_MAX;
        
        for(int i=0; i<N; i++){
            int j = i+1, k = N-1;
            
            while(j < k){
                int sum = arr[i];
                sum += (arr[j] + arr[k]);
                
                if(sum == X) return sum;
                int currDiff = abs(sum - X);
                if(((currDiff) < minDiff) || ((currDiff) == minDiff && sum > X)){
                    minDiff = currDiff;
                    ans = sum;
                }
                
                if(sum < X)j++;
                else k--;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends