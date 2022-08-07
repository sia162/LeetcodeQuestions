class Solution {
public:
    int solveHere(int i,int j,vector<vector<int>> &dp){
        if( i<0 || j<0) return 0;
        if(i == 0 && j == 0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int right = solveHere(i,j-1,dp);
        int top = solveHere(i-1,j,dp);
        
        return dp[i][j] = right+top;
    }
    
    int uniquePaths(int m, int n) {
        //starting 
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solveHere(m-1,n-1,dp);
    }
};  