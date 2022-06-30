class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pre;
        
        int n = nums.size();
        pre.push_back(0);
        
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = sum + nums[i];
            pre.push_back(sum);
        }
        
        // pre.push_back(0);
        
        int ans = -1;
        
        for(int i=1;i<=n;i++){
            int left = pre[i-1];
            int right = pre[n] - pre[i];
            
            // cout<<left<<" "<<right<<endl;
            
            if(left == right){
                ans = i-1;
                break;
            }
        }
       
        
        return ans;
    }
}; 