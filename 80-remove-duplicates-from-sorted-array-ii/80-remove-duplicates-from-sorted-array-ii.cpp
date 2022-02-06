class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int count = 0;
      
       
        for(int i=0,j=0;j<nums.size();){
            
            while(j<nums.size() && nums[i]==nums[j]) {
                count++; j++;
            };
            
            if(count>2){
                int t = i;
                i = i + 2;
                nums.erase(nums.begin() + i, nums.begin() + j);
                count = 0;
                i=j=t;
            }else{
                count = 0;
                i=j;
            }
        }
        
        return nums.size();
    }
};