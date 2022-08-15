class Solution {
public:
    int solvehere(vector<vector<int>>& mat,int i,int j,int n,vector<vector<int>> &dp){
        if (j < 0 || j >= n) return 1e9; // Base Case 1: out of bound
        if (i == 0) return mat[i][j]; // Base Case 2: end point - 0th row
        if(dp[i][j] != -1) return dp[i][j];
         
        int top = mat[i][j] + solvehere(mat, i - 1, j, n,dp);
        int top_left = mat[i][j] + solvehere(mat, i - 1, j - 1, n,dp);
        int top_right = mat[i][j] + solvehere(mat, i - 1, j + 1, n,dp);
        
        return dp[i][j] = min(top, min(top_left, top_right));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int min_path_sum = 1e9;
        vector<vector<int>> dp(n,vector<int>(n,-1));;
        
        for (int j = 0; j < n; j++) {
            min_path_sum = min(min_path_sum, solvehere(matrix, n - 1, j, n,dp));
        }
        
        return min_path_sum;
    }
};