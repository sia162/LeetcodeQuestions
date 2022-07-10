class Solution {
public:
    void revStr(vector<char>& s,int l,int r){
        if(l>=r) return;
        
        swap(s[l],s[r]);
        revStr(s,l+1,r-1);
    }
    
    void reverseString(vector<char>& s) {
    
        // reverse(s.begin(), s.end());
        // for(int i=0,j=s.size()-1;i<j;i++,j--) swap(s[i],s[j]);
        
        revStr(s,0,s.size()-1);
    }
};