class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int low = 1;
        int high = nums.size()-1;
        int main = nums[0];
        
        while(low<high){
           int m = low+(high-low)/2;
            if(nums[m]<main)
                high=m;
            else
                low=m+1;
        }
        
        int ans = min(nums[low],main);
        return ans;
    }
};