class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
        int words = 0;
        
        for(int i=0;i<sentences.size();i++){
            int c = 0;
            for(int j=0;j<sentences[i].size();j++){
                char w = sentences[i][j];
                if(w == ' ') c++;
                if(j == sentences[i].size()-1) c++;
            }
            
            words = max(c,words);
        }
        
        return words;
    }
};