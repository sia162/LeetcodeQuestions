//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int node,vector<int> adj[],vector<int>& vis,stack<int> &s){
        vis[node] = 1;
        
        for(auto c:adj[node]){
            if(!vis[c]){
                dfs(c,adj,vis,s);
            }
        }
        
        s.push(node);
        return;
    }
    
    void checkdfs(int node,vector<int> adj[],vector<int>& vischeck){
        vischeck[node] = 1;
        for(auto c:adj[node]){
            if(!vischeck[c]){
                checkdfs(c,adj,vischeck);
            }
        }
        
        return;
    }
    
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    stack<int> s;
	    vector<int> vis(V,0);
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj,vis,s);
	        }
	    }
	    
	    int ansnode = s.top();
	    vector<int> vischeck(V,0);
	    
	    checkdfs(ansnode,adj,vischeck);
	    
	    for(int i=0;i<V;i++){
	        if(!vischeck[i]) return -1;
	    }
	    
	    return ansnode;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends