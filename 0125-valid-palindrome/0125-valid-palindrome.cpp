class Solution {
public:
    bool isPalindrome(string s) {
        
        for(int i=0,j=s.length()-1;i<=j;){
            if(!isalnum(s[i])) i++;
            else if(!isalnum(s[j])) j--;
            else if(s[i] == ' ') i++;
            else if(s[j] == ' ') j--;
            else if(tolower(s[i]) != tolower(s[j])) return false;
            else {
                i++;
                j--;
            }
        }
        
        return true;
    }
};