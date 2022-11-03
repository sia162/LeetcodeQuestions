class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int ans = 0;
        unordered_map<char,int> m;
        
        for(int i=0,j=0;i<=j && j<s.length() && i<s.length();){
            if(m.find(s[j]) == m.end()){
                ans = max(ans,j-i+1);
                m[s[j]] = j;
                j++;
            }else{
                // i = m[s[j]] + 1;
                while(i<(m[s[j]] + 1)){
                    m.erase(s[i]);
                    i++;
                }
                
                // i++;
                m[s[j]] = j;
                j++;
            }
        }
        
        return ans;
    }
};