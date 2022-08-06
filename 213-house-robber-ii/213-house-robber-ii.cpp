class Solution {
public:
    int solveHere(int n,vector<int> num,vector<int> &dp){
        if(n == 0) return num[n];
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        
        int pick = num[n] + solveHere(n-2,num,dp);
        int notpick = 0 + solveHere(n-1,num,dp);
        
        return dp[n] = max(pick,notpick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
     
        vector<int> nums1; //leaving first
        vector<int> nums2;  //leaving last
        
        for(int i=0;i<n;i++){
            if(i!=0) nums1.push_back(nums[i]);
            if(i!=n-1) nums2.push_back(nums[i]);
        }
        
        
        vector<int> dp(n+1,-1);
        int ans1 = solveHere(n-2,nums1,dp); //leaving first
        
        vector<int> dpp(n+1,-1);
        int ans2 = solveHere(n-2,nums2,dpp); //leaving last
        
        return max(ans1,ans2);
    }
};