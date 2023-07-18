//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isValid(int x, int y, int N){
        return x >= 0 && y >= 0 && x < N && y < N;
    }
    
    int bfs(vector<int>&KnightPos, vector<int>&TargetPos, vector<vector<int>> &vis,
    vector<vector<int>> &level, int N, int INF)
    {
        int sourceX = KnightPos[0] - 1, sourceY = KnightPos[1] - 1;
	    int destX = TargetPos[0] - 1, destY = TargetPos[1] - 1;
	    
	    vector<pair<int, int>> movements = {
            {-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};

        queue<pair<int, int>> q;
        q.push({sourceX, sourceY});
        vis[sourceX][sourceY] = 1;
        level[sourceX][sourceY] = 0;
        //level[sourceX][sourceY] = 0;
        while (!q.empty())
        {
            pair<int, int> v = q.front();
            int x, y;
            x = v.first, y = v.second;
            q.pop();

            for (auto movement : movements)
            {
                int childX = movement.first + x;
                int childY = movement.second + y;

                if (!isValid(childX, childY, N))
                    continue;
                if (!vis[childX][childY])
                {
                    q.push({childX, childY});
                    level[childX][childY] = level[x][y] + 1;
                    vis[childX][childY] = 1;
                }
            }
            
            if(level[destX][destY] != INF) break;
        
        }

        return level[destX][destY];
    }

    
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    
	    // Code here
	    int INF = 1e9 + 7;
	    vector<vector<int>> vis(N, vector<int>(N,0));
	    vector<vector<int>> level(N, vector<int>(N,INF));
	    
	    return bfs(KnightPos, TargetPos, vis , level, N, INF);
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends