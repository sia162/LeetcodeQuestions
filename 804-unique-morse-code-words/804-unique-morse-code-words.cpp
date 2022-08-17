class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.",
                         "....","..",".---","-.-",".-..","--","-.",
                         "---",".--.","--.-",".-.","...","-","..-",
                         "...-",".--","-..-","-.--","--.."};
        
        unordered_map<string,int> mp;
        
        
        for(auto word: words){
            string code;
            for(auto alpha: word){
                code.append(morse[alpha - 97]);
            }
            mp[code]++;
        }
        
        return mp.size();    
    }
};