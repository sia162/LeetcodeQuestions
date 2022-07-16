class Solution {
public:
    void solveHere(vector<int> nums,vector<int> &perms,vector<vector<int>> &ans,unordered_map<int,bool> &marked){
        if(marked.size() == nums.size()){
            ans.push_back(perms);
            return;
        }
        
        
        for(int i=0;i<nums.size();i++){
            if(marked.find(i) == marked.end() || !marked[i]){
                marked[i] = true;
                perms.push_back(nums[i]);
                
                solveHere(nums,perms,ans,marked);
                
                marked.erase(i);
                perms.pop_back();
            }
            
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,bool> marked;
        vector<int> perms;
        vector<vector<int>> ansperms;
        
        solveHere(nums,perms,ansperms,marked);
        
        return ansperms;
        
    }
};