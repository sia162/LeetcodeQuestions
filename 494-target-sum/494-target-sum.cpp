int mod = 1e9 + 7;
class Solution {
public:
    int solvehere(int ind,vector<int> &nums,int tar){
        // if(tar == 0) return 1;
        if(ind == 0){
            if(tar == 0 && nums[0] == 0) return 2;
            if(tar == 0 || tar == nums[0]) return 1;
            return 0;
        }
        
        int pick = 0;
        if(nums[ind]<=tar) pick = solvehere(ind-1,nums,tar-nums[ind]);
        int notpick = 0 + solvehere(ind-1,nums,tar);
        
        return (pick + notpick)%mod;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        //s1-s2 = D
        //s1 = (target + tosum )/2
        
        int toSum = 0;
        for(auto v:nums) toSum+=v;
        
        int t = toSum - target;
        if(t < 0 || t%2!=0) return 0;
        
        int n = nums.size();
        return solvehere(n-1,nums,t/2);
    }
};