class Solution {
public:
//     int solveHere(vector<vector<int>>& dp,vector<vector<int>>& og,int i,int j){
//         if(i>=0 && j>=0 && og[i][j] == 1) return 0;
//         if(i == 0 && j == 0) return 1;
//         if(i<0 || j<0) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int l = solveHere(dp,og,i-1,j);
//         int r = solveHere(dp,og,i,j-1);
//         return dp[i][j] = l+r;
//     }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
            
        vector<vector<int>> dp(m,vector<int> (n,-1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                else if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int l=0,r=0;
                    if(i>0)  l = dp[i-1][j];
                    if(j>0)  r = dp[i][j-1];

                    dp[i][j] = r+l;
                }
            }
        }
        
        return dp[m-1][n-1];
        // return solveHere(dp,obstacleGrid,m-1,n-1);
    }
};