class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 1) return 1;
        
        int maxlen = 0;
        
        for(int i=0;i<s.length();i++){
            
            string str = "";
            for(int j=i;j<s.length();j++){
                if(str.find(s[j]) == string::npos)
                    str = str + s[j];
                else{
                    int l = str.length();
                    maxlen = max(maxlen,l);
                    break;
                }
            }
            
            int l = str.length();
            maxlen = max(maxlen,l);
        }
        
        return maxlen; 
    }
};