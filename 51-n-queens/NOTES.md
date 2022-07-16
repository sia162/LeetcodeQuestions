void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n){
if(col == n){
ans.push_back(board);
return;
}
for(int row=0;row<n;row++){
if(isSafe(col,row,n,board)){
board[row][col] = 'Q';
solve(col+1,board,ans,n);
board[row][col] = '.';
}
}
}
vector<vector<string>> solveNQueens(int n) {
vector<vector<string>> ans;
vector<string> board(n);
string s(n,'.');
for(int i=0;i<n;i++) board[i] = s;
solve(0,board,ans,n);
return ans;
}
```
​
***approach 2 | n^2***