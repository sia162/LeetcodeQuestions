class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
     
        if(nums.size()<3) return 0;
        
        int count = 0;
        int prevdiff = nums[1]-nums[0];
        int currcount = 0;
        
        for(int i=1;i<nums.size()-1;i++){
            int currdiff = nums[i+1] - nums[i];
            
            if(currdiff == prevdiff) currcount++;
            else{
                prevdiff = currdiff;
                currcount = 0;
            }
            
          count +=currcount;
        }
        
        return count;
    }
};