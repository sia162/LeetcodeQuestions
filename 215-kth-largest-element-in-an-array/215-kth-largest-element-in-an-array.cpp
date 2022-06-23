class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int ans = nums[nums.size()-k];
        return ans;
    }
};

// 1 2 3 4 5 6
