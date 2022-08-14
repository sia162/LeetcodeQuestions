class Solution {
public:
    int solvehere(vector<vector<int>>& triangle,int i,int j,int m,vector<vector<int>> &dp){
        if(i == m-1) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        int b = triangle[i][j] + solvehere(triangle,i+1,j,m,dp);
        int br = triangle[i][j] + solvehere(triangle,i+1,j+1,m,dp);
        
        return dp[i][j] = min(b,br);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m=triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        
        return solvehere(triangle,0,0,m,dp);
    }
};