```
class Solution {
public:
int kthSmallest(vector<vector<int>>& matrix, int k) {
priority_queue<int> pq;
for(int i=0;i<matrix.size();i++){
for(int j=0;j<matrix[0].size();j++){
if(k==0){
if(matrix[i][j] < pq.top()){
pq.pop();
pq.push(matrix[i][j]);
}
}else {
pq.push(matrix[i][j]);
k--;
}
}
}
return pq.top();
}
};
```