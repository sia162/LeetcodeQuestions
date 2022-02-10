class Solution {
public:
    int majorityElement(vector<int>& nums) {
      unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++) m[nums[i]]++;
        
        int maxe = 0;
        int ans = nums[0];
        for(auto it:m){
            if(it.second > maxe){
                maxe = it.second;
                ans = it.first;
            }
        }
        
        return ans;
    }
};


// curr = 1
// maj = 1
// ans = 2
// 2 3 3