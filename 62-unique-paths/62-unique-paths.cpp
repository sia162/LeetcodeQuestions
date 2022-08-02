class Solution {
public:
    
//     int dp[101][101];
    
//     int solveHere(int m,int n,int i,int j){
//         if(i>m || j>n) return 0;
//         if(i == m-1 && j == n-1) return 1;
//         if(dp[i][j]) return dp[i][j];
//         return dp[i][j] = solveHere(m,n,i+1,j) + solveHere(m,n,i,j+1);
//     }
    
    int uniquePaths(int m, int n) {
        // return solveHere(m,n,0,0);
        
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++) dp[i][n-1] = 1;
        for(int j=0;j<n;j++) dp[m-1][j] = 1;
        
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        
        return dp[0][0];
    }
};