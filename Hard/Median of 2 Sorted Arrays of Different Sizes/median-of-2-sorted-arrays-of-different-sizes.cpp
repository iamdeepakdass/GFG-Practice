//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        int n = array1.size();
        int m = array2.size();
        int i = 0;
        int j = 0;
        vector<int> temp;
        
        while(i < n && j < m){
            if(array1[i] < array2[j]){
                temp.push_back(array1[i++]);
            }
            else{
                temp.push_back(array2[j++]);
            }
        }
        
        while(i < n){
            temp.push_back(array1[i++]);
        }
        
        while(j < m){
            temp.push_back(array2[j++]);
        }
        // sort(array1.begin(), array1.end());
        // sort(array2.begin(), array2.end());
        
        // vector<int> temp;
        
        // for(int i=0; i<n; i++){
        //     temp.push_back(array1[i]);
        // }
        
        // for(int i=0; i<m; i++){
        //     temp.push_back(array2[i]);
        // }
        
        // double ans = 0;
        int k = temp.size();
        
        // for(int i=0; i<k; i++){
        //     cout<<temp[i]<<" ";
        // }
        
        if(k%2 == 0){
           return double(temp[(k-1)/2] + temp[k/2])/2;
        }
        
        else{
            return double(temp[k/2]);
        }
        
        //return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends