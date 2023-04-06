//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    
    int equalSum(int N, vector<int> &A) {
        // code here
        int idx = -1;
        int left_sum = A[0]; 
        int right_sum = 0;
        
        if(N == 1){
            return 1;
        }
        
        for(int i=2; i<N; i++){
            right_sum += A[i];
        }
        
        for(int i=1; i<N-1; i++){
            if(left_sum == right_sum){
                return i+1;
                break;
            }
            else{
                left_sum += A[i];
                right_sum -= A[i+1];
            }
        }
        
        return idx;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N; 
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.equalSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends