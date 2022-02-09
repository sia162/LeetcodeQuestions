class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        
        unordered_map<int,int> m;
        for(int i =0;i<nums.size();i++) m[nums[i]]++;
        
        for(auto &[n,cnt] : m){
            if(k!=0 && m.count(n+k)) ans++;
            else if(k==0 && cnt>1) ans++;
        }
       
        return ans;
    }
};