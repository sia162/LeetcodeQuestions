//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node,vector<int> &vis,vector<int> adjlist[],int V){
        vis[node] = 1;
        
        for(auto ng: adjlist[node]){
            if(!vis[ng]) dfs(ng,vis,adjlist,V);
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> adjlist[V];
        
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j] == 1 && i!=j){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(V+1,0);
        int pcount = 0;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                //new component
                pcount++;
                dfs(i,vis,adjlist,V);
            }
        }
        
        return pcount;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends