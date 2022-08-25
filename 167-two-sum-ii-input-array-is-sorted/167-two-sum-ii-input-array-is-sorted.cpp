class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        // unordered_map<int,int> m;
        // for(auto v:numbers)
        
        for(int i=0,j=numbers.size()-1;i<j;){
            if(numbers[i] + numbers[j] == target) return {i+1,j+1};
            else if(numbers[i] + numbers[j] > target) j--;
            else i++;
        }
        
        return {-1,-1};
    }
};