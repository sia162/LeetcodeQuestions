class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        
        vector<vector<int>> ans;
        int count = -1;
      
        for(int i=0;i<34;i++){
            vector<int> row(i+1,0);
            row[0] = 1;
            row[i] = 1;
            
            for(int j=1;j<i;j++){
                row[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            
            count++;
            if(count == rowIndex) return row;
            ans.push_back(row);
        }
        
        return {};
    }
};