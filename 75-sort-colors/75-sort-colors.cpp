class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> m;
        
        for(auto v: nums) m[v]++;
        
        int i=0;
        for(auto [v,c]:m){
            while(c--){
                nums[i] = v;
                i++;
            }
        }
        
    }
};