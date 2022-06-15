class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        unordered_map<string,int> m;
        sort(words.begin(),words.end(),[&](string s1,string s2){
            return s1.size()<s2.size();
        });
        
        int ans = 0;
        
        for(auto word:words){
            
            for(int i=0;i<word.size();i++){
                //word = bca
                //predecessors = ca,ba,bc
                string predecessor = word.substr(0,i) + word.substr(i+1);
                m[word] = max(m[word],m[predecessor] + 1);
            }
            
            ans = max(ans,m[word]);
        }
        
        return ans;
    }
};