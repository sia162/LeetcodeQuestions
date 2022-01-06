class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        set<int> s2;
        
        for(auto e:nums1) s1.insert(e);
        for(auto f:nums2) s2.insert(f);
        
        set<int> s;
        
        for(auto e: s1){
            if(s2.find(e)!=s2.end()) s.insert(e);
        }
        
        for(auto e: s2){
            if(s1.find(e)!=s1.end()) s.insert(e);
        }
        
        vector<int> v;
        for(auto val: s) v.push_back(val);
        
        return v;
    }
};