class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 1) return 1;
        
        int maxlen = 0;
        unordered_set<char> st;
        
        for(int i=0,j=0;j<s.length();){
            if(st.find(s[j]) == st.end()){
                st.insert(s[j++]);
                maxlen = max(maxlen,j-i);
            }else{
                st.erase(s[i]);
                i++;
            }
        }
        
        return maxlen; 
    }
};