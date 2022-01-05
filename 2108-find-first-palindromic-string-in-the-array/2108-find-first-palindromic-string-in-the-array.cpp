class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        int i,j;
        string ans ="";
        
        for(auto s: words){
            
            i=0,j=s.length()-1;
            while(i<=j){
                if(s[i]!=s[j]){
                  break;
                }
                i++;
                j--;
            }
            
            if(i>j){
                ans = s;
                break;
            }
        }
        
        return ans;
        
    }
};