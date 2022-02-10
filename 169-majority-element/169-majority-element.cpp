class Solution {
public:
    int majorityElement(vector<int>& nums) {
//Moore's Voting Algorithm
        int count = 0;
        int majority;
        
        for(int i =0;i<nums.size();i++){
            if(count == 0){majority = nums[i]; count++;}
            else if(majority == nums[i]){count++;}
            else{count --;}
        }
        
        // if answer value was not guaranteed then we will have to iterate 
        // once to check if it is actually having the count of n/2
        
        return majority;
    }
};


// curr = 1
// maj = 1
// ans = 2
// 2 3 3