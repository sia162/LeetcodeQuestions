//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool checkBipartiteWithDFS(int node,vector<int>adj[],int V, vector<int>& color){
        if(color[node] == -1) color[node] = 0;
        
        for(auto adjnode: adj[node]){
            if(color[adjnode] == -1){
                color[adjnode] = !color[node];
                
               if(!checkBipartiteWithDFS(adjnode,adj,V,color)) return false;
            }else if(color[adjnode] == color[node]) return false;
        }
        
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V+1,-1);
	    
	    for(int i=0;i<V;i++){
	        if(color[i] == -1){
	            if(!checkBipartiteWithDFS(i,adj,V,color)) return false;
	        }
	    }
	    
	    return true;
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
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends