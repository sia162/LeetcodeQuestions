class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        priority_queue<int> pq;
        int min_element = INT_MAX;

        for(int i=0;i<nums.size();i++){
            int tobepushed;
            if(nums[i]%2!=0) tobepushed = nums[i]*2;
            else tobepushed = nums[i];
            
            pq.push(tobepushed);
            min_element = min(min_element,tobepushed);
        }
        
        int min_diff = INT_MAX;
        int maxele = pq.top();
        pq.pop();
        
        while(maxele%2==0){
            min_diff = min(min_diff, (maxele - min_element));
            pq.push(maxele/2);
            min_element = min(min_element,maxele/2);
            
            maxele = pq.top();
            pq.pop();
        }
        
        
        return min(min_diff,maxele - min_element);
    }
};