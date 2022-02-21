class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majority;
        
        for(int i =0;i<nums.size();i++){
            if(count == 0){majority = nums[i]; count++;}
            else if(majority == nums[i]){count++;}
            else{count --;}
        }
        
        return majority;
    }
};


// curr = 1
// maj = 1
// ans = 2
// 2 3 3