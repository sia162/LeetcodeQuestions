class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int mid1=-1,mid2=-1;
        if(nums.size()%2 == 0){
            mid1 = nums.size()/2;
            mid2 = nums.size()/2 -1;
        }else{
            mid1 = (nums.size() - 1)/2;
        }
            
        
        int sum1=0,sum2=0;
        for(int i=0;i<nums.size();i++){
            if(mid1!=-1){
                sum1 = sum1 + abs(nums[i]-nums[mid1]); 
            }
            
            if(mid2!=-1){
                sum2 = sum2 + abs(nums[i]-nums[mid2]); 
            }
        }
        
        int ans;
   
        // cout<<sum1<<" "<<sum2;
        
        if(mid2!=-1){
            ans = sum2;
        }else if(mid1!=-1){
            ans = sum1;
        }else{
            ans = min(sum1,sum2);
        }
        
        return ans;
    }
};