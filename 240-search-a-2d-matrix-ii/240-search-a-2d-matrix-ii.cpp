class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        int i = 0, j = n - 1;
        
        while(i < m && j >= 0  && i >= 0 && j < n){
            if(matrix[i][j] == target) return true;
            
            if(target < matrix[i][j]) j--;
            else if(target > matrix[i][j]) i++;
        } 
        
        return false;
    }
};