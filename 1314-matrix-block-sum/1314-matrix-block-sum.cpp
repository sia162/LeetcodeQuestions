class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        
        
        vector<vector<int>> prefixsum = mat;
        vector<vector<int>> answer = prefixsum;

        //prefix sum
        for(int i=0;i<mat.size();i++){
            int sum = 0;
            for(int j=0;j<mat[i].size();j++)
            { 
                sum = sum + mat[i][j];
                
                if(i==0) prefixsum[i][j] = sum;
                else {
                    prefixsum[i][j] = sum + prefixsum[i-1][j];
                }
               
            }
        }
            
        
        for(int i=0;i<mat.size();i++){
            //sum
            for(int j=0;j<mat[i].size();j++){
                int Ilow = (i-k)<0 ? 0 : i-k;
                int Iup = (i+k)>=mat.size()? mat.size()-1 : i+k;
                
                int Jlow = (j-k)<0 ? 0 : j-k;
                int Jup = (j+k)>=mat[0].size()? mat[0].size()-1 : j+k;
                
                answer[i][j] = prefixsum[Iup][Jup] - 
                    ((Ilow == 0) ? 0 : prefixsum[Ilow-1][Jup]) - 
                    ((Jlow == 0) ? 0 : prefixsum[Iup][Jlow-1]) + 
                    ((Ilow == 0) || (Jlow == 0)  ? 0 : prefixsum[Ilow-1][Jlow-1]);
                
            }
        }
    
        return answer;    
    }
};