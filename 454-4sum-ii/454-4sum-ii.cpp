class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int,int> m;
        
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                m[nums1[i]+nums2[j]]++;
            }
        }
        
        int count = 0;
        
        for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums4.size();j++){
                int needed = 0 - (nums3[i]+nums4[j]);
                
                if(m.count(needed)){
                    count += m[needed];
                }
            }
        }
        
        
        return count;
        
    }
};