class Solution {
public:
    char findTheDifference(string s, string t) {
        
        if(s.length() == 0)
            return t[0];
        
        int i;
        for(i=0;i<t.length();i++){
            if(count(s.begin(),s.end(),t[i]) != count(t.begin(),t.end(),t[i]))
                break;
        }
        
        return t[i];
    }
};