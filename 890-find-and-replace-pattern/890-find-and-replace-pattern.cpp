class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        int j;
        
        for(int i=0;i<words.size();i++){
            string s = words[i];
            if(s.size()!=pattern.size()) continue;
            
            unordered_map<char,char> m1;
            unordered_map<char,char> m2;
            
            
            for(j=0;j<s.size();j++){
                if(m1.find(pattern[j])!=m1.end() || m2.find(s[j])!=m2.end()){
                    if(m1[pattern[j]] != s[j] || m2[s[j]] !=pattern[j] ) break;
                }else{
                    m1[pattern[j]] = s[j];
                    m2[s[j]] = pattern[j];
                }
            }
            
            if(j>=s.size()) ans.push_back(s);
        }
        
        return ans;
    }
};