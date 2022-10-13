class Solution {
public: 
    int countPalindromicSubsequence(string s) {
        vector<int> left(26);
        vector<int> right(26);
        
        unordered_set<string> uset;
        
        for(int i=0;i<s.length();i++) right[s[i] - 'a']++;
        
        for(int i=0;i<s.length();i++){
            right[s[i] - 'a']--;
            
            for(int j=0;j<26;j++){
                if(left[j]>0 && right[j]>0){
                    char c = 'a' + j;
                    
                    string palin;
                    palin.push_back(c);
                    palin.push_back(s[i]);
                    palin.push_back(c);
                    
                    uset.insert(palin);
                }
            }
            
            left[s[i] - 'a']++;
        }
        
        return uset.size();
    }
};