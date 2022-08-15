class Solution {
public:    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int min_path_sum = 1e9;
        vector<vector<int>> dp(n,vector<int>(n,-1));;
        
        for(int j=0;j<n;j++) dp[0][j] = matrix[0][j]; //base case
            
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++) { //j is depend on i for each i j can be all possible values 0,1,2..n-1 
                
                int top = 1e9, top_left = 1e9, top_right = 1e9;

                top = matrix[i][j] + dp[i - 1][j];
                if(j-1>=0) top_left = matrix[i][j] + dp[i - 1][j - 1];
                if(j+1<n) top_right = matrix[i][j] + dp[i - 1][j + 1];

                dp[i][j] = min(top, min(top_left, top_right));
                 
            }
        } 
        
        for (int j = 0; j < n; j++) min_path_sum = min(min_path_sum, dp[n - 1][j]);
        return min_path_sum;
    }
};