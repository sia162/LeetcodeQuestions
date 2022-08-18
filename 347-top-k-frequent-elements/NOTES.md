**APPROCH 2**
```
vector<int> topKFrequent(vector<int>& nums, int k) {
vector<int> ans;
unordered_map<int,int> m;
for(auto val: nums) m[val]++;
priority_queue<pair<int,int>> pq;
for(auto [v,f]: m) pq.push({f,v});
while(k--){
ans.push_back(pq.top().second);
pq.pop();
}
return ans;
}
```
​
​
​
​
​
​
​
​
​
​