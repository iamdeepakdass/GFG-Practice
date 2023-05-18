//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        // Your code goes here
        int startRow = 0;
        int lastRow = n-1;
        int startCol = 0;
        int lastCol = m-1;
        vector<int> mat_element;
        int count = 0;
        int total = n*m;
        
        while(count < total){
            // Printing upper row
            for(int index = startCol; count<total &&  index<=lastCol; index++){
                mat_element.push_back(a[startRow][index]);
                count++;
            }
            startRow++;
            
            // Printing Right Column
            for(int index =startRow; count<total &&  index <= lastRow; index++){
                mat_element.push_back(a[index][lastCol]);
                count++;
            }
            lastCol--;
            
            // Printing lower row
            
            for(int index = lastCol; count<total &&  index >= startCol; index--){
                mat_element.push_back(a[lastRow][index]);
                count++;
            }
            lastRow--;
            
            // Printing left column
            
            for(int index = lastRow; count<total &&  index>=startRow; index--){
                mat_element.push_back(a[index][startCol]);
                count++;
            }
            startCol++;
        }
        
        return mat_element[k-1];
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends