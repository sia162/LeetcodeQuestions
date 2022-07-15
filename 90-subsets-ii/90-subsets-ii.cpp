class Solution {
public:
    void subsetsII(int i, vector<int> nums,vector<int> &seq,vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(seq);
            return;
        }
      
        seq.push_back(nums[i]);
        subsetsII(i+1,nums,seq,ans);
        seq.pop_back();
        subsetsII(i+1,nums,seq,ans);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> seq;
        vector<vector<int>> ans;
        
        subsetsII(0,nums,seq,ans);
        
        set<vector<int>> s;
        for(auto it: ans){
            sort(it.begin(),it.end());
            s.insert(it);
        }
        
        vector<vector<int>> finalans;
        
        for(auto it: s) finalans.push_back(it);
        
        return finalans;
    }
};