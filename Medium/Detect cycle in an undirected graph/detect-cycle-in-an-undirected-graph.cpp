//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
 
    bool dfs(int vertex, int parent, vector<int> adj[], bool vis[]){
        
        vis[vertex] = true;
        bool isLoop = false;
        
        for(int child : adj[vertex]){
            if(vis[child] && child == parent){
                continue;
            }
            if(vis[child]) return true;
            
            isLoop |= dfs(child, vertex, adj, vis);
        }
        
        return isLoop;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool vis[V + 10] = {false};
        
        for(int i = 0; i < V; i++){
            if(vis[i])continue;
            
            if(dfs(i,-1, adj, vis)){
                return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends