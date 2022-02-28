class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> v;
        
        int top=0;
        int bottom=matrix.size();
        int left=0;
        int right=matrix[0].size();
        
        
        int i;
        
        while(left<right && top<bottom){
    
            i=left;
            while(i!=right){
                v.push_back(matrix[top][i]);
                i++;
            }
            top++;
            
            if(left>=right && top>=bottom) break;
            
            
            i=top;
            while(i!=bottom){
                v.push_back(matrix[i][right-1]);
                i++;
            }
            right--;
            
            
            if(left>=right || top>=bottom) break;
            
            
            i=right-1;
            while(i>=left){
                v.push_back(matrix[bottom-1][i]);
                i--;
            }
            bottom--;
           
            if(left>=right && top>=bottom) break;
            
            i=bottom-1;
            while(i>=top){
                v.push_back(matrix[i][left]);
                i--;
            }
            left++;
        }
        
        return v;
        
    }
};