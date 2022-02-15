class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        if(nums.size() == 1)
            return nums[0];
        
        //no stack,no queue,no hasmap,no array
        //no sort
        //no binary search
        //two pointer? sliding window?
        
        //HOW?      T = 0(N)?     S = 0(1)?
        
        //Bit Manipulation?
        
        for (int i=1;i<nums.size();i++){
            nums[i] = nums[i-1]^nums[i];
            cout<<nums[i]<<" ";
        }
          
        return nums[nums.size()-1];
    }
};