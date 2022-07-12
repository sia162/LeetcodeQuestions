class Solution {
public: 
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> max_heap;
        for(int i=0;i<nums.size();i++) max_heap.push({nums[i],i});
        
        vector<pair<int,int>> tobeans;
        while(k){
            tobeans.push_back(max_heap.top());
            max_heap.pop();
            k--;
        }
        
        sort(tobeans.begin(),tobeans.end(),[](pair<int,int> a,pair<int,int> b){
           return a.second<b.second; 
        });
        
        vector<int> ans;
        for(auto it:tobeans){
            ans.push_back(it.first);
        }
        
        return ans;
    }
};