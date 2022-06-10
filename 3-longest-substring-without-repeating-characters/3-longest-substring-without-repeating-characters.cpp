class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 1) return 1;
        
        unordered_set<char> st; 
        
        int maxs = 0;
        int i=0,j=0;
            
        while(j<s.length() && i<s.length()){
         
            if(st.find(s[j]) == st.end()){
                st.insert(s[j++]);
                maxs = max(maxs,j-i);
            }else{
                st.erase(s[i++]);
            }
        }
        
        return maxs;
    }
};
