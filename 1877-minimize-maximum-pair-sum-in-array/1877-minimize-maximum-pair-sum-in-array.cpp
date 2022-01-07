class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
            
        int sum = INT_MIN;
        for(int i=0,j=nums.size()-1;i<j;i++,j--){
           sum = max(sum,nums[i]+nums[j]);
        }
        
        return sum;
    }
};