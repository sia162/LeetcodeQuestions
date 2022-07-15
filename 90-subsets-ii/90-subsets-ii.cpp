class Solution {
public:
 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
       
       set<vector<int>> setsub;
       
        for(int i = 0;i < (1<<n); i++){
            vector<int> now;
            
            for(int j = 0 ;j < n; j++){
                if(i&(1<<j)){
                    now.push_back(nums[j]);
                }
            }
            
            setsub.insert(now);
        }
       
       
        vector<vector<int>> ans;
        for(auto it : setsub){
            ans.push_back(it);
        }
        return ans;
    }
};