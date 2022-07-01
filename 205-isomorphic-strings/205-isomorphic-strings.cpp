class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        
        unordered_map<char,int> m;
        unordered_map<char,int> n;
        
        for(int i=0;i<s.length();i++){
            if(m.find(s[i]) == m.end()) m[s[i]] = i;
            s[i] = m[s[i]] + '0';
            
            if(n.find(t[i]) == n.end()) n[t[i]] = i;
            t[i] = n[t[i]] + '0';
        }
        
        cout<<s<<" "<<t;

        
        // int i = 10;
        // char a = i+'0';
        // cout<<a;
        
       return s == t;
        
        
    }
};