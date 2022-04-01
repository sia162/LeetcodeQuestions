class Solution {
public:
    void reverseString(vector<char>& s) {
    
        // reverse(s.begin(), s.end());
        // for(int i=0,j=s.size()-1;i<j;i++,j--) swap(s[i],s[j]);
        int i = 0, j = s.size() - 1;
        while(i < j){
            swap(s[i++], s[j--]); 
        }
        
    }
};