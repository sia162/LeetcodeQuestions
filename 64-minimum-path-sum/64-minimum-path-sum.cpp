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
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0] = grid[0][0];
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j] = grid[0][0];
                else{
                    int l = INT_MAX,r=INT_MAX;
                    if(i>=1) l = grid[i][j] + dp[i-1][j];
                    if(j>=1) r = grid[i][j] + dp[i][j-1];
                    
                    dp[i][j] = min(l,r);
                }
            }
        }
        
        return dp[m-1][n-1];
        
        // return solveHere(grid,m-1,n-1,dp);
    }
};