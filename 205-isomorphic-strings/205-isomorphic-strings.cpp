class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        
        unordered_map<char,char> m;
        unordered_map<char,char> n;
        int ans1 = true,ans2 = true;
        
        for(int i=0;i<s.length();i++){
            if(m.find(s[i]) == m.end()) m[s[i]] = t[i];
            else {
                if(m[s[i]]!=t[i]){
                    ans1 = false;
                    break;
                }
            }
        }
        
        for(int i=0;i<s.length();i++){
            if(n.find(t[i]) == n.end()) n[t[i]] = s[i];
            else {
                if(n[t[i]]!=s[i]){
                    ans2 = false;
                    break;
                }
            }
        }
        
        return ans1 && ans2;
        
    }
};