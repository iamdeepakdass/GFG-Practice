//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isSafe(int i, int j, int n, vector<vector<int>> &matrix){
        return (i >= n || j >= n || matrix[i][j] == 0) ? false : true;
    }
    
    bool solveMaze(int i, int j, int n, vector<vector<int>> &matrix, vector<vector<int>> &ans){
        
        if(i == n-1 && j == n-1){
            ans[i][j] = 1;
            return true;
        }
        int jump = matrix[i][j];
        for(int k=1; k<=jump; k++){
            if(k+j < n && (matrix[i][k+j] != 0 || k+j == n-1)){
                ans[i][k+j] = 1;
                if(solveMaze(i,k+j, n, matrix, ans))return true;
                ans[i][k+j] = 0;
            }
            
            if(k+i < n && (matrix[i+k][j] != 0 || i+k == n-1)){
                ans[i+k][j] = 1;
                if(solveMaze(i+k, j, n, matrix, ans))return true;
                ans[i+k][j] = 0;
            }
        }
        
        return false;
    }
    
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   // Code here
	   int n = matrix.size();
	   vector<vector<int>> ans(n, vector<int>(n,0));
	   ans[0][0] = 1;
	   
	   if(solveMaze(0, 0, n, matrix, ans)) return ans;
	   
	   return {{-1}};
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends