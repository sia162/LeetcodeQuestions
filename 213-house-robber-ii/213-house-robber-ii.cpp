class Solution {
public:
    int solveHere(vector<int> arr){
        int n = arr.size();
        int prev2 = -1;
        int prev1 = arr[0];
	    
	   for(int i=1;i<n;i++){
	       int pick = arr[i]; if(i>1) pick += prev2;
	       int notpick = 0 + prev1;
	       
	       int curr = max(pick,notpick);
	       
	       prev2 = prev1;
	       prev1 = curr;
	   } 
	  
	  return prev1;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
     
        vector<int> nums1; //leaving first
        vector<int> nums2;  //leaving last
        
        for(int i=0;i<n;i++){
            if(i!=0) nums1.push_back(nums[i]);
            if(i!=n-1) nums2.push_back(nums[i]);
        }
        
        int ans1 = solveHere(nums1); //leaving first
        int ans2 = solveHere(nums2); //leaving last
        
        return max(ans1,ans2);
    }
};