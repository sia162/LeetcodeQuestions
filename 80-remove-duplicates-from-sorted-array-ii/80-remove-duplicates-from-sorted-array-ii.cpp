class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int j=1,count=1;
        
        for(int i=0;i<nums.size();i++){
            
            if(i>0 && nums[i] == nums[i-1] && count<2){
                nums[j] = nums[i];
                count++;
                j++;
            }
            
            if(i>0 && nums[i] != nums[i-1]){
                nums[j] = nums[i];
                j++;
                count=1;
            }
        }
        
        
        return j;
        
//         int count = 0;
//         for(int i=0,j=0;j<nums.size();){
//             while(j<nums.size() && nums[i]==nums[j]) {
//                 count++; j++;
//             }; 
//             if(count>2){
//                 int t = i;
//                 i = i + 2;
//                 nums.erase(nums.begin() + i, nums.begin() + j);
//                 count = 0;
//                 i=j=t;
//             }else{
//                 count = 0;
//                 i=j;
//             }
//         }
//         return nums.size();
    }
};