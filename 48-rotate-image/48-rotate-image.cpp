class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        if(matrix.size()==1) return;
        
        int left=0;
        int right=matrix[0].size()-1;
        int top=0;
        int bottom=matrix.size()-1;
        
        int temp;
        while(top<right && left<bottom){
            
            temp=left;
            for(int i=top;temp<right && i<bottom;i++,temp++){
                swap(matrix[top][temp],matrix[i][right]);
            }
            
            temp=left;
            for(int i=right;temp<right && i>left;i--,temp++){
                swap(matrix[top][temp],matrix[bottom][i]);
            }
            
            temp=left;
            for(int i=bottom;temp<right && i>top;i--,temp++){
                swap(matrix[top][temp],matrix[i][left]);
            }
            
            top++;
            right--;
            bottom--;
            left++;
        }
    }
};