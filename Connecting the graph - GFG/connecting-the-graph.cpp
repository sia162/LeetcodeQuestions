//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisJointSet{
    public: 
        vector<int> parent,rank,size;
        
        DisJointSet(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);
            size.resize(n+1,1);
            
            for(int i=0;i<=n;i++){
                parent[i] = i;
            }
        }
        
        
        int findParent(int node){
            if(parent[node] == node) return node;
            
            return parent[node] = findParent(parent[node]);
        } 
        
        
        void unionByRank(int u,int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            
            if(ulp_u == ulp_v) return;
            
            if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }else if(rank[ulp_v] > rank[ulp_u]){
                parent[ulp_u] = ulp_v;
            }else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
        
        //little changes
        void unionBySize(int u,int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            
            if(ulp_u == ulp_v) return;
            
            if(size[ulp_u] > size[ulp_v]){
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }else if(size[ulp_v] >= size[ulp_u]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
        }
        
};


class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        DisJointSet ds(n);
        
        int extraEdges = 0;
        for (auto it : edge) {
            int u = it[0];
            int v = it[1];
            
            if (ds.findParent(u) == ds.findParent(v)) {
                extraEdges++;
            }
            else {
                ds.unionBySize(u, v);
            }
        }
        
        int compCount = 0;
        for(int i=0;i<n;i++){
            if(ds.findParent(i) == i) compCount++;
        }
        
        
        if(extraEdges >= compCount - 1) return compCount - 1;
        return -1;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends