//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool checkBipartiteWithBfs(int i,vector<int>adj[],int V, vector<int>& color){
        queue<int> q;
	    q.push(i);
	    color[i] = 0;
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        for(auto adjnode : adj[node]){
	            if(color[adjnode] == -1){
	                color[adjnode] = !color[node];
	                q.push(adjnode);
	            }else if(color[adjnode] == color[node]){
	                return false;
	            }
	        }
	    }
	    
	    return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V+1,-1);
	    
	    for(int i=0;i<V;i++){
	        if(color[i] == -1){
	            if(!checkBipartiteWithBfs(i,adj,V,color)) return false;
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