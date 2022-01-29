class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        priority_queue<int> pq{nums.begin(),nums.end()};
        
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        return (a-1)*(b-1);
    }
};