//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj[n+1];
        for(auto v:edges){
            int n1 = v[0];
            int n2 = v[1];
            int wt = v[2];
            
            vector<int> t1,t2;
            
            t1.push_back(n1);
            t1.push_back(wt);
            adj[n2].push_back(t1);
            
            t2.push_back(n2);
            t2.push_back(wt);
            adj[n1].push_back(t2);
        }
        
        
        vector<int> dist(n+2,1e9);
        dist[1] = 0;
        
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++) parent[i] = i;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        parent[1] = 1;
        
        while(!pq.empty()){
            int disTillNow = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int edgewt = it[1];
                int adjNode = it[0];
                
                if(disTillNow + edgewt < dist[adjNode]){
                     dist[adjNode] = disTillNow + edgewt;
                     pq.push({dist[adjNode],adjNode});
                     parent[adjNode] =  node;
                }
            }
        }
        
        if(dist[n] == 1e9) return {-1};
        
        vector<int> ans;
        int node = n;
        ans.push_back(node);
        while(parent[node]!=node){
            int pre = parent[node];
            ans.push_back(pre);
            node = pre;
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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