class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() < 2) return true;
        
        for(int i=0,j=s.length()-1;i<=j;){
            while(i<j && !isalnum(s[i])) i++;
            while(i<j && !isalnum(s[j])) j--;
            
            if(i>j) return false;
            if(tolower(s[i]) != tolower(s[j])) return false;
            
            i++;
            j--;
        }
        
        return true;
    }
};