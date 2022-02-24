class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int r = matrix.size();
        int c = matrix[0].size();
        bool i0flag = false;
        
        for(int i=0 ; i<r ; i++){
             //setting just flags
            if(matrix[i][0] == 0) i0flag = true;
            
            for(int j=1 ; j<c ; j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=r-1;i>=0;i--){
           for(int j=c-1;j>=1;j--){
               if(matrix[i][0] == 0 || matrix[0][j] == 0)
                   matrix[i][j] = 0;
           } 
            if(i0flag) matrix[i][0] = 0;
        }
        
    }
};


                    