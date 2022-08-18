class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> m;
        
        for(auto val: nums) m[val]++;
        
        vector<pair<int,int>> v;
        for(auto [val,f]: m) v.push_back({val,f});
        
        sort(v.begin(),v.end(),[](pair<int,int> &a,pair<int,int> &b){
            return a.second>b.second;
        });
        
        int i=0;
        while(k){
            k--;
            ans.push_back(v[i].first);
            i++;
        }
        
        return ans;
    }
};