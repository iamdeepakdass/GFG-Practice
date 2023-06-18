//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int col, int n, vector<vector<int>>&ans,vector<int>&board, vector<int>&leftRow, 
    vector<int>&upperDiag, vector<int>&lowerDiag){
        if(col == n){
            ans.push_back(board);
            return;
        }    
        
        for(int row=0; row<n; row++){
            if(leftRow[row] == 0 && upperDiag[n-1+col-row] == 0 && lowerDiag[row+col] == 0){
                
                leftRow[row] = 1;
                lowerDiag[row+col] = 1;
                upperDiag[n-1+col-row] = 1;
                board.push_back(row+1);
                solve(col+1,n,ans,board,leftRow,upperDiag,lowerDiag);
                board.pop_back();
                leftRow[row] = 0;
                lowerDiag[row+col] = 0;
                upperDiag[n-1+col-row] = 0;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>ans;
        vector<int>board;
        
        vector<int>leftRow(n,0), upperDiag(2*n-1, 0), lowerDiag(2*n-1,0);
        
        solve(0,n,ans,board,leftRow, upperDiag, lowerDiag);
        
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
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends