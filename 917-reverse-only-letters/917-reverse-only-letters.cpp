class Solution {
public:
    string reverseOnlyLetters(string s) {
        
        for(int i=0,j=s.length()-1;i<j;){
            
            if(i<s.length() && !isalpha(s[i])) i++;
            if(j>=0 && !isalpha(s[j])) j--;
            
            if(isalpha(s[i]) && isalpha(s[j])) {swap(s[i],s[j]); i++;j--;};   
        }
        
        return s;
    }
};