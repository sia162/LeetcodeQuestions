class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> m;
        int sum=0,ans=0;
        
        int i=0,j=0;
        
        while(j<nums.size() && i<=j){
            if(m.find(nums[j]) == m.end()){
                sum = sum + nums[j];
                m[nums[j]] = j;
                j++;
            }else{
                sum = sum - nums[i];
                m.erase(nums[i]);
                i++;
            }
            
            ans = max(ans,sum);
        }
        
        return ans;
        
    }
};