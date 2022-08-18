class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        
        unordered_map<char,int> m;
        
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            m[t[i]]--;
        }
   
        
        for(auto v:s){
            if(m[v] != 0) return false;
        }
        
        return true;
    }
};