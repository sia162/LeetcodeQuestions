class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        
        int n = nums.size();
        vector<int> ans(n);
        int i=0,j=n-1;
        
        for (int p = n - 1; p >= 0; p--) {
            if (abs(nums[i]) > abs(nums[j])) {
                ans[p] = nums[i] * nums[i];
                i++;
            } else {
                ans[p] = nums[j] * nums[j];
                j--;
            }
        }
        
   return ans;
                
    }
};