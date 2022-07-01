// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
  bool checkForCycle(int node,vector<int>& vis,vector<int> adj[]){
      queue<pair<int,int>> q;
      q.push({node,-1});
      
      vis[node] = true;
      
      while(!q.empty()){
          int n = q.front().first;
          int parent = q.front().second;
          q.pop();
          
          for(auto val:adj[n]){
              if(vis[val]!=true){vis[val] = true; q.push({val,n});}
              else if(vis[val] == true && parent!=val){
                  return true;
              }
          }
      }
      
      return false;
  }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
         vector < int > vis(V + 1, 0);
          for (int i = 0; i < V; i++) {
            if (!vis[i]) {
              if (checkForCycle(i, vis, adj)) return true;
            }
          }
        
        return false;
    }
};

// { Driver Code Starts.
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
}  // } Driver Code Ends