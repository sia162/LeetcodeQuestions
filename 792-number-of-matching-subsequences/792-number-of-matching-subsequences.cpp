class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>> m;
        
        for(int i=0;i<s.length();i++){
            m[s[i]].push_back(i);
        }
        
        int count = 0;
        int j,k;
        
        for(int i=0;i<words.size();i++){
            string t = words[i];
            int curr = -1;
            
            for(j=0;j<t.length();j++){
                auto it = upper_bound(m[t[j]].begin(),m[t[j]].end(),curr);
                if(it == m[t[j]].end()) break;
                curr = *it;
                if(j == t.size()-1) count++;
            }
            
        }
        
        return count;
    }
};