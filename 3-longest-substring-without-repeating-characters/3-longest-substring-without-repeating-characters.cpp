class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 1) return 1;
        
        int maxlen = 0;
        unordered_map<char,int> m;
        
        for(int i=0,j=0;j<s.length();j++){
            if(m.find(s[j]) == m.end() || m[s[j]] == 0){
                m[s[j]]++;
            }else{
                int l = m.size();
                maxlen = max(maxlen,l);
                while(i<s.length() && s[i]!=s[j]){
                    m.erase(s[i]);
                    i++;
                }
                i++;
            }
            
            int l = m.size();
            maxlen = max(maxlen,l);
        }
        
        return maxlen; 
    }
};