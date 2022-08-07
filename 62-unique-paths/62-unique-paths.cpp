class Solution {
public:
//     int solveHere(int i,int j,vector<vector<int>> &dp){
//         if( i<0 || j<0) return 0;
//         if(i == 0 && j == 0) return 1;
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int right = solveHere(i,j-1,dp);
//         int top = solveHere(i-1,j,dp);
        
//         return dp[i][j] = right+top;
//     }
    
    int uniquePaths(int m, int n) {
     
        vector<vector<int>> dp(m,vector<int>(n,1));
        // return solveHere(m-1,n-1,dp);

        
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                int r = dp[i][j+1];
                int b = dp[i+1][j];
                
                dp[i][j] = r+b;
            }
        }
        
        return dp[0][0];
    }
};  