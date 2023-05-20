//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
        int startRow = 0;
        int lastRow = n-1;
        int startCol = 0;
        int lastCol = m-1;
        int count = 0;
        int max_count = n*m;
        vector<int> ans;
        
        // Printing upper Row
        for(int index=startCol; count<=max_count && index<=lastCol; index++){
            ans.push_back(matrix[startRow][index]);
            count++;
        }
        startRow++;
        
        // Printing last Column
        for(int index=startRow; count<=max_count && index<=lastRow; index++){
            ans.push_back(matrix[index][lastCol]);
            count++;
        }
        lastCol--;
        
        // Printing lower Row
        if(startRow <= lastRow){
            for(int index=lastCol; count<=max_count && index>=startCol; index--){
            ans.push_back(matrix[lastRow][index]);
            count++;
        }
        lastRow--;
        }
        
        // Printing first Column
        if(startCol <= lastCol){
            for(int index=lastRow; count<=max_count && index>=startRow; index--){
            ans.push_back(matrix[index][startCol]);
            count++;
        }
        startCol++;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends