class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        for (int num = 0; num < (1 << n); num++) {
            vector<int> sub;
            
            for (int i = 0; i < n; i++) {
                //check if the ith bit is set or not
                if (num & (1 << i)) {
                    sub.push_back(nums[i]);
                }
            }
            
            // if (sub.size() > 0) {
                ans.push_back(sub);
            // }
        }
        
        // sort(ans.begin(), ans.end());
        return ans;
    }
};