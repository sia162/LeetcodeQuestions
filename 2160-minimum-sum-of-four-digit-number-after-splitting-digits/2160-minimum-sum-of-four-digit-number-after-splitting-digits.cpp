class Solution {
public:
    int minimumSum(int num) {
        
        vector<int> nums;
        int r;
        while(num!=0){
            r = num%10;
            nums.push_back(r);
            num = num/10;
        }
        
        sort(nums.begin(),nums.end());
        
        int minsum = (nums[0]*10 + nums[3]) + (nums[1]*10 + nums[2]);
        return minsum;
    }
};

// 2 2 3 9
// 0 0 4 9