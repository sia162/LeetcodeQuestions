class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        
        int low = 0;
        int high = nums.size()-1;
        int main = nums[0];
        
        if(nums[low]<nums[high]) return nums[0];
        
        while(low<=high){
           int m = low+(high-low)/2;
            
            if(nums[m]>nums[m+1]) return nums[m+1];
            if(nums[m]<nums[m-1]) return nums[m];
        
            if(nums[m]<main)
                high=m-1;
            else
                low=m+1;
        }
        
        return -1;
    }
};