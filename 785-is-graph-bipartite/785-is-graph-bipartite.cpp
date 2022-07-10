class Solution {
public:
    
    bool isBiSolveHereDfs(int i,vector<vector<int>> graph,vector<int>& colorvis){
        if(colorvis[i] == -1)
            colorvis[i] = 1;
     
        for(auto n : graph[i]){
            if(colorvis[n] == -1){
                colorvis[n] = !colorvis[i];
                
                if(!isBiSolveHereDfs(n,graph,colorvis)) return false;
            }else if(colorvis[n] == colorvis[i]){
                return false;
            }
        }

        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int> colorvis(graph.size(),-1);
        
        for(int i=0;i<graph.size();i++){
            if(colorvis[i] == -1){
                if(!isBiSolveHereDfs(i,graph,colorvis))
                    return false;
            }
        }
        
        return true;
    }
};