class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        
        unordered_map<int,int> m;
        for(auto val: nums) m[val]++;
        
        vector<vector<int>> buck(nums.size()+1);
        
        for(auto [val,freq]: m){
            buck[freq].push_back(val);
        }
        
        reverse(buck.begin(),buck.end());
        
        for(auto buc: buck){
            for(auto i: buc){
                ans.push_back(i);
                
                if(k == ans.size()) return ans;
            }
        }
        
        return ans;
    }
};