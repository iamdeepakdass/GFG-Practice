//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        int k = 1e6 + 10;
        vector<int> dis(N,k);
        int i;
        
        dis[0] = 0;
        
        for(i=0; i<M; i++){
            if(dis[edges[i][1]] > dis[edges[i][0]] + edges[i][2]){
                dis[edges[i][1]] = dis[edges[i][0]] + edges[i][2];
            }
        }
        
        for(i=0; i<N; i++){
            if(dis[i] == k){
                dis[i] = -1;
            }
        }
        
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends