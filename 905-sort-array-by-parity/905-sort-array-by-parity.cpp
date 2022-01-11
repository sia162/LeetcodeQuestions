class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        // [2,6,4,5,3,3,7]
        //      i j
        
        for(int i=0,j=nums.size()-1;i<j;){
            if(nums[i]%2==0) i++;
            if(nums[j]%2!=0) j--;
            
            if(i<j && nums[i]%2!=0 && nums[j]%2==0)
               { swap(nums[i],nums[j]);
               i++;j--;}
        }
        
        return nums;
        
    }
};