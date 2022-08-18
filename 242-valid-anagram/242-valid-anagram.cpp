class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        
        
        for(int i=0;i<s.size();i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }
   
        
        for(auto v:s){
            if(m1[v] != m2[v]) return false;
        }
        
        return true;
    }
};