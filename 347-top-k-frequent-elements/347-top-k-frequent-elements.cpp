class Solution {
public:
    
        
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        if(nums.size() <= 1){
            return nums;
        }

        unordered_map<int,int> m;
        for(auto val: nums) m[val]++;
        
        vector<pair<int,int>> p;
        
        for(auto it: m){
            p.push_back({it.first,it.second});  
        }
        
         sort(p.begin(),p.end(), [&](pair<int,int> a,pair<int,int> b){
             return a.second>b.second;
        });
        
        vector<int> ans;
        
        for(auto v: p){
            if(k==0){
                break;
            }
            
            ans.push_back(v.first);
            k--;
        }
        
        
        return ans;
        
    }
};