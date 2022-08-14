class Solution {
public:
//     int solveHere(vector<vector<int>>& grid, int i,int j,vector<vector<int>> &dp){
//         if(i<0 || j<0) return INT_MAX;
//         if(i==0 && j==0) return grid[i][j];
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int l = INT_MAX,r=INT_MAX;
//         if(i>=1) l = grid[i][j] + solveHere(grid,i-1,j,dp);
//         if(j>=1) r = grid[i][j] + solveHere(grid,i,j-1,dp);
        
//         return dp[i][j] = min(l,r);
//     }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
     
        vector<int> prev(n,0);
        
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            
            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[j] = grid[0][0];
                else{
                    
                    int l = INT_MAX,r=INT_MAX;
                    if(i>=1) l = grid[i][j] + prev[j];
                    if(j>=1) r = grid[i][j] + curr[j-1];
                    
                    curr[j] = min(l,r);
                }
            }
            
            prev = curr;
        }
        
        return prev[n-1];
    }
};