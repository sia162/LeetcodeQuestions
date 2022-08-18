return nums;
}
unordered_map<int,int> mp;
for(int i=0;i<nums.size();i++) mp[nums[i]]++;
vector<vector<int>> v(nums.size()+1);
for(auto it: mp){
// cout<<it.second<<it.first<<endl;
v[it.second].push_back(it.first);
}
vector<int> ans;
for(int i=v.size()-1;i>=1;i--){
// cout<<v[i].size();
for(int j=0;j<v[i].size();j++){
ans.push_back(v[i][j]);
if (ans.size() == k) return ans;
}
}
return ans;
}
};
```
​