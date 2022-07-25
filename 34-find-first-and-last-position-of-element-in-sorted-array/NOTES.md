```
class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {
vector<int> ans(2,-1);
if(nums.empty()) return ans;
int n = nums.size();
int l=0,h=nums.size()-1;
while(l<=h){
int m = l + (h-l)/2;
if(m==0 && nums[m]==target || nums[m]==target && nums[m-1]!=target){
ans[0] = m;
break;
}
if(target>nums[m]){
l = m+1;
}else{
h=m-1;
}
}
l=0,h=nums.size()-1;
while(l<=h){
int m = l + (h-l)/2;
if(m==n-1 && nums[m]==target || nums[m]==target && nums[m+1]!=target){
ans[1] = m;
break;
}
if(target<nums[m]){
h = m-1;
}else{
l = m+1;
}
}
return ans;
}
};
```