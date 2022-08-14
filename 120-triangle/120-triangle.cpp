class Solution {
public:
//     int solvehere(vector<vector<int>>& triangle,int i,int j,int m,vector<vector<int>> &dp){
//         if(i == m-1) return triangle[i][j];
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int b = triangle[i][j] + solvehere(triangle,i+1,j,m,dp);
//         int br = triangle[i][j] + solvehere(triangle,i+1,j+1,m,dp);
        
//         return dp[i][j] = min(b,br);
//     }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m=triangle.size();
        vector<int> front(m,0);
        
        
        for(int i=m-1;i>=0;i--){
            vector<int> curr(m,0);
            
            for(int j=i;j>=0;j--){
                if(i == m-1) curr[j] = triangle[i][j];
                else{
                    
                    int b = triangle[i][j] + front[j];
                    int br = triangle[i][j] + front[j+1];

                    curr[j] = min(b,br);
                }
            }
            
            front = curr;
        }
        
        return front[0]; 
    }
};