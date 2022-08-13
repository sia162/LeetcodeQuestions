class Solution {
public:
    int solveHere(vector<vector<int>>& dp,vector<vector<int>>& og,int i,int j){
        if(i>=0 && j>=0 && og[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int l = solveHere(dp,og,i-1,j);
        int r = solveHere(dp,og,i,j-1);
        
        return dp[i][j] = l+r;
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
            
        vector<vector<int>> dp(m,vector<int> (n,-1));
        
        return solveHere(dp,obstacleGrid,m-1,n-1);
    }
};