class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()>t.length()) return false;
        
        int jStart = 0;
        
        int count = 0;
        for(int i=0;i<s.length();i++){
            char toMatch = s[i];
            
            for(int j=jStart;j<t.length();j++){
                if(toMatch == t[j]){
                    count++;
                    jStart = j+1;
                    break;
                }
            }
        }
        
        if(count == s.length()) return true;
        
        return false;
        
    }
};