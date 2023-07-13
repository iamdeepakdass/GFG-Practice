//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool dfs(int vertex, int parent, vector<int> graph[], bool vis[], bool checked[])
    {
        if(checked[vertex]) return false;
        if(vis[vertex]) return true;
        vis[vertex] = true;
        bool isLoopExist = false;
    
        for (int child : graph[vertex])
        {
            if (vis[child])
                return true;

            isLoopExist |= dfs(child, vertex, graph, vis, checked);
            checked[child] = true;
        
        }
        
        vis[vertex] = false;
        return isLoopExist;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        bool vis [V+10] = {false};
        bool checked [V+10] = {false};
        
        for(int i=0; i<V; i++){
            if(vis[i])continue;
            
            if(dfs(i, -1, adj, vis, checked)){
                return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends