class Solution {
public:
//     bool solvehere(int ind,int target,vector<int> nums,vector<vector<int>> &dp){
//         if(target == 0) return true;
//         if(ind == 0) return nums[ind] == target;
//         if(dp[ind][target] != -1) return dp[ind][target];
        
//         bool pick = false;
//         if(nums[ind]<=target) pick = solvehere(ind-1,target-nums[ind],nums,dp);
//         bool notpick = solvehere(ind-1,target,nums,dp);
        
//         return dp[ind][target] = pick || notpick;
//     }
    
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(int i=0;i<nums.size();i++)  sum+=nums[i];
        if(sum%2 != 0) return false;
        
        int n = nums.size();
        if(n == 1) return false;
         
        int target = sum/2;
        vector<vector<bool>> dp(n,vector<bool>(target+1,0));
        
        for(int i=0;i<n;i++) dp[i][0] = true;
        if(nums[0]<=target) dp[0][nums[0]] = true;
        
        for(int i=1;i<n;i++){
            for(int t=1;t<=target;t++){
                
                bool pick = false;
                if(nums[i]<=t) pick = dp[i-1][t-nums[i]];
                bool notpick = dp[i-1][t];

                dp[i][t] = pick || notpick;
            }
        }
        
        return dp[n-1][target];
        
        // return solvehere(n-1,target,nums,dp);
    }
};