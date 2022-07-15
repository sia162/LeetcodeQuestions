class Solution {
public:
    void dfsGraphTrav(vector<vector<char>> &grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return; //edge cases
        
        if(grid[i][j] == '0' || grid[i][j] == '2') return; //returning in case visited or water
        
        grid[i][j] = '2'; //marking visited
        
        dfsGraphTrav(grid,i,j-1);
        dfsGraphTrav(grid,i,j+1);
        dfsGraphTrav(grid,i+1,j);
        dfsGraphTrav(grid,i-1,j);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        
        int islands = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    dfsGraphTrav(grid,i,j);
                    islands++;
                }
            }
        }
        
        return islands;
    }
};