**APPROCH 2**
```
return nums;
}
unordered_map<int,int> mp; //index and count
priority_queue<pair<int,int>> pq; //index
for(int i=0;i<nums.size();i++) mp[nums[i]]++;
for(auto it: mp){
pq.push({it.second,it.first});
}
vector<int> ans;
while(k){
ans.push_back(pq.top().second);
pq.pop();
k--;
}
return ans;
```
​
​