class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maximum = INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if((nums[i]-1)*(nums[j]-1) > maximum)
                    maximum = (nums[i]-1)*(nums[j]-1);
            }
        }
        
        return maximum;
        
    }
};