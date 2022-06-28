class Solution {
public:    
    int minDeletions(string s) {
        
        vector<int> freq(26, 0);
        
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int deleteCount = 0;
       
        unordered_set<int> seenFreq;
        
        for (int i = 0; i < 26; i++) {
            while (freq[i] && seenFreq.find(freq[i]) != seenFreq.end()) {
                freq[i]--;
                deleteCount++;
            }
        
            seenFreq.insert(freq[i]);
        }
        
        return deleteCount;
        
    }
};