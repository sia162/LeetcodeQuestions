class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = -1;
        
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0] == target) return true;
            
            if(matrix[i][0] < target){
                r = i;
            }
        }
   

        if(r == -1) return false;
        // matrix[r][0,1,2...]
        
        int low = 0;
        int high = matrix[0].size()-1;
        
        while(low<matrix[0].size() && low<=high){
            int mid = (low+high)/2;
   
            if(matrix[r][mid] == target) return true;
            else if(target > matrix[r][mid]) low = mid + 1;
            else high = mid - 1;
        }
        
        return false;
    }
};