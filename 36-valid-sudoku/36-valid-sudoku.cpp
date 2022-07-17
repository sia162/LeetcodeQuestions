class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        bool sudo = true;
        int n = board.size();
            
        for(int i=0;i<9;i++){
            vector<int> check(n+1,0);

            for(int j=0;j<9;j++){
                if(board[i][j] == '.')
                    continue;
                
                if(isdigit(int(board[i][j]))){
                    
                    int index = board[i][j] - '0';
                    if(check[index] == 1){
                        return false;
                    }
                    
                    check[index] = 1;
                }
               
            }
        }
        
   
        for(int j=0;j<9;j++){
            vector<int> check(n+1,0);
        
            for(int i=0;i<9;i++){
                if(board[i][j] == '.')
                    continue;
                
                if(isdigit(int(board[i][j]))){
                    int index = board[i][j] - '0';
                    if(check[index] == 1){
                        return false;
                    }
                    check[index] = 1;
                }
            }
        }
        
        
   
        for(int kc=0;kc<9;kc+=3){
            for(int kr=0;kr<9;kr+=3){
                vector<int> check(n+1,0);
                
                for(int i=kr;i<kr+3;i++){
                    for(int j=kc;j<kc+3;j++){
                        
                        if(isdigit(int(board[i][j]))){
                            if(board[i][j] == '.')
                                continue;
                            
                            int index = board[i][j] - '0';
                            if(check[index] == 1){
                                return false;
                                break;
                            }
                            check[index] = 1;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};