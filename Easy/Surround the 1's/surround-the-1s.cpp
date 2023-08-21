//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int>>& matrix) {
        // Code here
        int n = matrix.size();
        int m = matrix[0].size();
        
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 1){
                    int cnt = 0;
                    if(i>0 && matrix[i-1][j] == 0)cnt++;
                    if(j>0 && matrix[i][j-1] == 0)cnt++;
                    if(i<n-1 && matrix[i+1][j] == 0)cnt++;
                    if(j<m-1 && matrix[i][j+1] == 0)cnt++;
                     
                    if(i>0 && j>0 && matrix[i-1][j-1] == 0) cnt++;
                    if(j<m-1 && i>0 && matrix[i-1][j+1] == 0) cnt++;
                    if(i<n-1 && j>0 && matrix[i+1][j-1] == 0) cnt++;
                    if(j<m-1 && i<n-1 && matrix[i+1][j+1] == 0) cnt++;
                    
                    if(cnt == 0)continue;
                    if(!(cnt&1))ans++;
                }
            }
        }
        
        return ans;
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
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends