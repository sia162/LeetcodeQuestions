class Solution {
public:
        int helper(vector<int>& nums, int target, vector<int>& dp){
            if(target == 0) return 1; 
            if(dp[target] != -1) return dp[target]; 
            
            dp[target] = 0;
            
            for(auto& num : nums) 
                if(num <= target) dp[target] += helper(nums, target - num, dp);
            return dp[target];
        }
    
        int combinationSum4(vector<int>& nums, int target) {
            vector<int> dp(target + 1, -1);
            return helper(nums, target, dp);
        }
    
    
    
//     void solveHere(vector<int> nums,int target,int &ans){
//         if(target == 0){
//             ans += 1;
//             return;
//         }
        
//         for(int i=0;i<nums.size();i++){
//            if(nums[i] <= target) solveHere(nums,target-nums[i],ans);
//         }
//     }
    
//     int combinationSum4(vector<int>& nums, int target) {
//         int ans = 0;
//         solveHere(nums,target,ans);
        
//         return ans;
//     }
};