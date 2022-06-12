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
            }else{
                int index = m[nums[j]] + 1;
                while(i!=index){
                    sum = sum - nums[i];
                    m.erase(nums[i]);
                    i++;
                }
                
                m[nums[j]] = j;
                sum = sum + nums[j];
            }
            
            ans = max(ans,sum);
            j++;
        }
        
        return ans;
        
    }
};