//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        // Code here
        int m = matrix.size();
        int n = matrix[0].size();
        int col[m] = {0};
        int row[n] = {0};
        vector<vector<int>> temp(m, vector<int>(n,0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    int upper = (i>0 ? matrix[i-1][j] : 0);
                    int lower = (i<m-1 ? matrix[i+1][j] : 0);
                    int left = (j>0 ? matrix[i][j-1] : 0);
                    int right = (j<n-1 ? matrix[i][j+1] : 0);
                    temp[i][j] = upper + lower + left + right;
                    
                }
            }
        }
        
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(temp[i][j] != 0){
                    if(i>0)matrix[i-1][j] = 0;
                    if(i<m-1)matrix[i+1][j] = 0;
                    if(j>0)matrix[i][j-1] = 0;
                    if(j<n-1)matrix[i][j+1] = 0;
                    matrix[i][j] = temp[i][j];
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends