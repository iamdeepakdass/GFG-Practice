//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    void dfs(int i, int j, int oldColor, int newColor, vector<vector<int>>& image){
        
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != oldColor){
            return;
        }
        
        image[i][j] = newColor;
        
        dfs(i+1, j, oldColor, newColor, image);
        dfs(i-1, j, oldColor, newColor, image);
        dfs(i, j+1, oldColor, newColor, image);
        dfs(i, j-1, oldColor, newColor, image);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int oldColor = image[sr][sc];
        
        if(oldColor != newColor){
            dfs(sr, sc, oldColor, newColor, image);
        }
        
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends