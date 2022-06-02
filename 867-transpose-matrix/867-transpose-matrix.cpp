class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        int M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> a(N,vector<int> (M,0));
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                a[j][i] = matrix[i][j];
            }
        }
        
        return a;
    }
};