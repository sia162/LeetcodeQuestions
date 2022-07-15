class Solution {
public:
    bool flag = true;
     void dfs(int x, int y, int m, int n, vector <vector <int>>&grid1, vector <vector <int>>&grid2, vector <vector <int>>&visited){
        if(x<0 or x>=m or y<0 or y>=n) return;
        if(visited[x][y] or grid2[x][y]==0) return;
        
        if(grid1[x][y] == 0) flag = false;
        
        visited[x][y] = 1;
        dfs(x-1,y,m,n,grid1,grid2,visited);
        dfs(x+1,y,m,n,grid1,grid2,visited);
        dfs(x,y-1,m,n,grid1,grid2,visited);
        dfs(x,y+1,m,n,grid1,grid2,visited);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid2[0].size(), count = 0;
        vector <vector <int>> visited(m,vector<int>(n,0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid2[i][j]==1){
                    if(!visited[i][j]){
                        flag = true;
                        dfs(i,j,m,n,grid1,grid2,visited);
                        if(flag) count++;
                    }
                }
            }
        }
        return count;
        
    }
};