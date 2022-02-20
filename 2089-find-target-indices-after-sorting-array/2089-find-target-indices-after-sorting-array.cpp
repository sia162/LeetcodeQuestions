class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int index = find(nums.begin(),nums.end(),target) - nums.begin();
        
        vector<int> ans;
        for(int i = index;i<nums.size();i++){
            if(nums[i]==target) ans.push_back(i);
            else break;
        }
        
        return ans;
        
    }
};