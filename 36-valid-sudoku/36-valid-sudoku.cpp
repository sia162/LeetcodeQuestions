class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 10;
        
        for(int i=0;i<9;i++){
            vector<int> check(n,0);
            
            for(int j=0;j<9;j++){
                int index = board[i][j] - '0';
                
                if(board[i][j] == '.') continue;
                if(check[index] == 1) return false;
                
                check[index] = 1;
            }
        }
        
        
        for(int j=0;j<9;j++){
            vector<int> check(n,0);
            
            for(int i=0;i<9;i++){
                int index = board[i][j] - '0';
                
                if(board[i][j] == '.') continue;
                if(check[index] == 1) return false;
                
                check[index] = 1;
            }
        }
        
        
        for(int r=0;r<3;r++){
            for(int c=0;c<3;c++){
                int starti = r*3;
                int endi = starti + 3;
                
                int startj = c*3;
                int endj = startj+3;
                
                vector<int> check(n,0);
                
                for(int i=starti;i<endi;i++){
                    for(int j=startj;j<endj;j++){
                        int index = board[i][j] - '0';
                        
                        if(board[i][j] == '.') continue;
                        if(check[index] == 1) return false;
                        check[index] = 1;
                    }
                }
            }
        }
        
        return true;
    }
};