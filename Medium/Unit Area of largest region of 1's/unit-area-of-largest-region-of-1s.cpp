//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    void dfs(int i, int j, vector<vector<int>>& grid, int &cnt){
        
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1){
            return;
        }    
        cnt++,
        grid[i][j] = 2;
        
        dfs(i+1, j, grid, cnt);
        dfs(i-1, j, grid, cnt);
        dfs(i, j+1, grid, cnt);
        dfs(i, j-1, grid, cnt);
        dfs(i-1, j-1, grid, cnt);
        dfs(i+1, j+1, grid, cnt);
        dfs(i+1, j-1, grid, cnt);
        dfs(i-1, j+1, grid, cnt);
    }
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int cnt = 0;
        int ans = 0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    //cnt++;
                    dfs(i, j, grid, cnt);
                    ans = max(cnt, ans);
                    cnt = 0;
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
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends