**APPROCH 2:**
sorting and maintaining count~
```
sort(nums.begin(),nums.end());
​
int maj = INT_MIN;
int curr = 1;
int ans = nums[0];
​
for(int i=1;i<nums.size();i++){
if(nums[i]==nums[i-1])
curr++;
else{
curr=1;
}
​
if(curr>maj){
maj = curr;
ans = nums[i-1];
}
}
​
return ans;
}
​
```
T - 0(NlogN)
S - 0(1)
​
**APPROCH 3:**
using hashmaps~
​
​