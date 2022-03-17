class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> answer;
        
        for(int i=0,j=0;j<nums.size();j++){
            
            //popping all less values from deque
            while(!dq.empty() && nums[dq.back()] < nums[j]) dq.pop_back();
            dq.push_back(j);
            
            //removing left element if window size increase
            if(i > dq.front()) dq.pop_front();
            
            //maintaining window size
            if(j+1 >= k){
                answer.push_back(nums[dq.front()]);
                i++;
            }
        }
       
        
        return answer;
    }
};

