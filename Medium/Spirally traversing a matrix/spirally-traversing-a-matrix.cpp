//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> ans;
        int count = 0;
        int total = r*c;
        
        int startRow = 0;
        int lastRow = r-1;
        int startCol = 0;
        int lastCol = c-1;
        
        while(count < total){
            
            for(int index=startCol; count<total && index<=lastCol; index++){
                ans.push_back(matrix[startRow][index]);
                count++;
            }
            startRow++;
            
            for(int index=startRow; count<total && index<=lastRow; index++){
                ans.push_back(matrix[index][lastCol]);
                count++;
            }
            lastCol--;
            
            for(int index=lastCol; count<total && index>=startCol; index--){
                ans.push_back(matrix[lastRow][index]);
                count++;
            }
            lastRow--;
            
            for(int index=lastRow; count<total && index>=startRow; index--){
                ans.push_back(matrix[index][startCol]);
                count++;
            }
            startCol++;
        }
        
        //reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends