class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()>t.length()) return false;
        
        int k = s.length();
        
        for(int i=0,j=0;i<s.length() && j<t.length();){
            if(s[i]==t[j]){
                i++;
                k--;
            }
            
            j++;
        }
        
        if(k)
            return false;
            
        return true;
        
    }
};