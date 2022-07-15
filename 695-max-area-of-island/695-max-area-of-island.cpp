class Solution {
public:
     void dfsGraphTrav(vector<vector<int>> &grid,int i,int j,int &area){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return; //edge cases
        
        if(grid[i][j] == 0 || grid[i][j] == 2) return; //returning in case visited or water
        
        grid[i][j] = 2; //marking visited
        area++;
        
        dfsGraphTrav(grid,i,j-1,area);
        dfsGraphTrav(grid,i,j+1,area);
        dfsGraphTrav(grid,i+1,j,area);
        dfsGraphTrav(grid,i-1,j,area);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        
        int islands = 0;
        int maxarea = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int area = 0;
                
                if(grid[i][j] == 1){
                    dfsGraphTrav(grid,i,j,area);
                    maxarea = max(maxarea,area);
                }
            }
        }
        
        return maxarea;
    }
};