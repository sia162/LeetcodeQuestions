class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        
        unordered_set<int> s(nums.begin(),nums.end());
        int ans = -1e9;
        
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1) != s.end()) continue;
            else{
                int count = 1;
                int num = nums[i]+1;
                    
                while(s.find(num)!=s.end()){
                    num++;
                    count++;
                }
                
                ans = max(ans,count);
            }
        }
        
        return ans;
    }
};