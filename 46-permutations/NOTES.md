***approach 1 | using map***
```
void solveHere(vector<int> nums,vector<int> &perms,vector<vector<int>> &ans,unordered_map<int,bool> &marked){
if(perms.size() == nums.size()){
ans.push_back(perms);
return;
}
for(int i=0;i<nums.size();i++){
if(!marked[i]){
marked[i] = 1;
perms.push_back(nums[i]);
solveHere(nums,perms,ans,marked);
marked[i] = 0;
perms.pop_back();
}
}
}
vector<vector<int>> permute(vector<int>& nums) {
unordered_map<int,bool> marked;
vector<int> perms;
vector<vector<int>> ansperms;
for(int i=0;i<nums.size();i++) marked[i] = 0;
solveHere(nums,perms,ansperms,marked);
return ansperms;
}
```