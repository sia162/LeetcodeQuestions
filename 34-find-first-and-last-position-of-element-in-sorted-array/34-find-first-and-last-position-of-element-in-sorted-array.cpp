class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans;
        int t = false;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target){
                ans.push_back(i);
                while(i<nums.size() && nums[i] == target){
                    i++;
                    t=true;
                }
                
                if(t && ans.size() == 1){
                    ans.push_back(i-1);
                    break;
                }
            }
        }
        
        
        if(ans.size() == 1){
            ans.push_back(ans[0]);
        }
        
        if(ans.size() == 0) return {-1,-1};
        
        return ans;
    }
};