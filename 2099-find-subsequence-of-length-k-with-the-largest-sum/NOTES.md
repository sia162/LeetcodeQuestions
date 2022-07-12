***recursive approch of finding subsequence***
​
```
void subsequence(int i,vector<int> nums,vector<int> &subs,int sum,vector<int>& ans,int& maxv,int k){
// if(subs.size()>k) return;
if(i>=nums.size()){
if(subs.size() == k && sum>maxv){
maxv = sum;
ans = subs;
}
return;
}
subs.push_back(nums[i]);
sum+=nums[i];
subsequence(i+1,nums,subs,sum,ans,maxv,k);
subs.pop_back();
sum-=nums[i];
subsequence(i+1,nums,subs,sum,ans,maxv,k);
}
vector<int> maxSubsequence(vector<int>& nums, int k) {
vector<int> subs;
int n = nums.size();
vector<int> ans;
int maxv = INT_MIN;
subsequence(0,nums,subs,0,ans,maxv,k);
return ans;
}
```
​
​