class Solution {
public:    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int min_path_sum = 1e9;
        
        vector<int> prev(n,0);
        for(int j=0;j<n;j++) prev[j] = matrix[0][j]; //base case
            
        for(int i=1;i<n;i++){
            vector<int> curr(n,0);
            
            for(int j=0;j<n;j++) { //j is depend on i for each i j can be all possible values 0,1,2..n-1 
                
                int top = 1e9, top_left = 1e9, top_right = 1e9;

                top = matrix[i][j] + prev[j];
                if(j-1>=0) top_left = matrix[i][j] + prev[j - 1];
                if(j+1<n) top_right = matrix[i][j] + prev[j + 1];

                curr[j] = min(top, min(top_left, top_right));
                 
            }
            
            prev = curr;
        } 
        
        for (int j = 0; j < n; j++) min_path_sum = min(min_path_sum, prev[j]);
        
        return min_path_sum;
    }
};