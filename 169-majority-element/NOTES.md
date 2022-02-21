​
​
**APPROCH 3:**
using hashmaps~
T- 0(N)
S- 0(N)
​
```
unordered_map<int,int> m;
for(int i=0;i<nums.size();i++) m[nums[i]]++;
int maxe = 0;
int ans = nums[0];
for(auto it:m){
if(it.second > maxe){
maxe = it.second;
ans = it.first;
}
}
return ans;
```
​
**APPROCH 4:**
T - 0(N)
S - 0(1)
​
Moore's Algorithm
```
int count = 0;
int majority;
for(int i =0;i<nums.size();i++){
if(count == 0){majority = nums[i]; count++;}
else if(majority == nums[i]){count++;}
else{count --;}
}
return majority;
```
​