class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto v:nums) m[v]++;
        
        for(auto [val,freq]: m){
            if(freq>=2) return true;
        }
        
        return false;
    }
};