//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void solve(int ind, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans){
        if(ind >= arr.size() || target < 0){
            return;
        }
        
        if(target == 0 && ind == arr.size()-1){
            ans.push_back(ds);
        }
        ds.push_back(arr[ind]);
        solve(ind, target-arr[ind], arr, ds, ans);
        ds.pop_back();
        solve(ind+1, target, arr, ds, ans);
    }
    
    vector<vector<int>> combinationSum(vector<int> &A, int B) {
        // Your code here
        set<int>st;
        int n = A.size();
        
        for(int i=0; i<n; i++){
            st.insert(A[i]);   
        }
        A.clear();
        vector<int> temp;
        for(auto it:st){
            temp.push_back(it);
        }
        sort(temp.begin(), temp.end());
        //cout<<A[0]<<A[1]<<A[2];
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,B,temp,ds,ans);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends