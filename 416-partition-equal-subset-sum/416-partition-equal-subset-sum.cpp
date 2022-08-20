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
        vector<int> prev(target+1,0);
        prev[0] = true;
        prev[nums[0]] == true;
        
        
        for(int i=1;i<n;i++){
            vector<int> curr(target+1,0);
            curr[0] = true;
            
            for(int t=1;t<=target;t++){
                
                bool pick = false;
                if(nums[i]<=t) pick = prev[t-nums[i]];
                bool notpick = prev[t];

                curr[t] = pick || notpick;
            }
            
            prev = curr;
        }
        
        return prev[target];
        
        // return solvehere(n-1,target,nums,dp);
    }
};