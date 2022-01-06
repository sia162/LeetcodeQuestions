class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(),nums1.end());
        
        vector<int> ans;
        for(auto e: nums2){
            if(s.erase(e)) ans.push_back(e);
        }
        
        return ans;
    }
};