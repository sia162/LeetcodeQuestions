class Solution {
public:
    void subsetsII(int ind, vector<int> nums,vector<int> &seq,vector<vector<int>> &ans){
        ans.push_back(seq);

        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i] == nums[i-1]) continue;
            
            seq.push_back(nums[i]);
            subsetsII(i+1,nums,seq,ans);
            seq.pop_back();
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> seq;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        subsetsII(0,nums,seq,ans);
        
        return ans;
        
    }
};