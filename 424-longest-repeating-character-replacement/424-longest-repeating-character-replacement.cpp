class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 0;
        unordered_map<char,int> m;
        
        int i=0,j=0;
        int maxFreqElementTillNow = 0;
        while(j<s.length()){
            m[s[j]]++;
            
            int windowlen = j-i+1;
            maxFreqElementTillNow = max(maxFreqElementTillNow,m[s[j]]);
            
            
            if((windowlen - maxFreqElementTillNow) > k){
                m[s[i]]--;
                i++;
            }
            
            windowlen = j-i+1;
            maxlen = max(maxlen,windowlen);
            j++;
        }
        
        return maxlen;
        
    }
};