**APPROCH #1**
*Extra Space*
​
```
vector<pair<int,int>> v;
for(int i=0;i<matrix.size();i++){
for(int j=0;j<matrix[0].size();j++){
if(matrix[i][j]==0){
v.push_back({i,j});
}
}
}
for(auto [i,j]: v){
int pr=i; int pc=0;
int qc=j; int qr=0;
while(pc<matrix[0].size())
{ matrix[pr][pc] = 0; pc++;}
while(qr<matrix.size())
{ matrix[qr][qc] = 0; qr++;}
}
```
​
**APPROCH #2**
*0(1) Space*