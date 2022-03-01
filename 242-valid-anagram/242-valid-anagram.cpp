class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(t.length()!=s.length()) return false;
        
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        
        for(int i=0;i<t.length();i++){
            m1[t[i]]++;
            m2[s[i]]++;
        }
        
        if(m1==m2)
            return true;
        
        return false;
    }
};