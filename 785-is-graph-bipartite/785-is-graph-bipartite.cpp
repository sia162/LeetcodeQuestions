class Solution {
public:
    
    bool isBiSolveHere(int i,vector<vector<int>> graph,vector<int>& colorvis){
        queue<int> q;
        
        q.push(i);
        colorvis[i] = 1;
        int tag;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            tag = true;
            
            for(auto n : graph[node]){
                if(colorvis[n] == -1){
                    q.push(n);
                    colorvis[n] = !colorvis[node];
                }else if(colorvis[n] == colorvis[node]){
                    tag = false;
                    break;
                }
            }
            
            if(tag == false)
                break;
        }
        
        
        if(tag == false) return false;
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int> colorvis(graph.size(),-1);
        
        for(int i=0;i<graph.size();i++){
            if(colorvis[i] == -1){
                if(!isBiSolveHere(i,graph,colorvis))
                    return false;
            }
        }
        
        return true;
    }
};