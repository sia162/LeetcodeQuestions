class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
          vector<vector<int>> ans;
  
        if(nums.size()<3)
        {
            return ans;
        }
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int low = i+1;
                int high = nums.size()-1;
                int tofind = 0 - nums[i];
                
                while(low<high){
                    if(nums[low] + nums[high] == tofind){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[low]);
                        v.push_back(nums[high]);
                        ans.push_back(v);
                        
                        while(low<high && nums[low] == nums[low+1]) low++;
                        while(low<high && nums[high] == nums[high-1]) high--;
                        low++;
                        high--;
                    }else if(nums[low] + nums[high] > tofind){
                        high--;
                    }else{
                        low++;
                    }
                }
            }
        }

     return ans; 
    }
};