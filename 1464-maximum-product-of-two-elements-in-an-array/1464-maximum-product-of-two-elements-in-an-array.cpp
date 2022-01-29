class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(),[](int a,int b){
            return a>b;
        });
        
        // greater<int>()
        return (nums[0]-1)*(nums[1]-1); 
    }
};