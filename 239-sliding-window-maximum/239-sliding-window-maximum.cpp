class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> answer;
        
        for(int i=0,j=0;j<nums.size();j++){
            pq.push({nums[j],j});
            
            if(j-i+1 >=k){
                answer.push_back(pq.top().first);
                while(!pq.empty() && pq.top().second <= i) pq.pop();
                i++;
            }
        }
        
        return answer;
    }
};

