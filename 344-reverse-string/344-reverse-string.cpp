class Solution {
public:
    void revStr(vector<char>& s,int i,int n){
        if(i>=n/2) return;
        
        swap(s[i],s[n-i-1]);
        
        revStr(s,i+1,n);
    }
    
    void reverseString(vector<char>& s) {
    
        // reverse(s.begin(), s.end());
        // for(int i=0,j=s.size()-1;i<j;i++,j--) swap(s[i],s[j]);
        
        int n = s.size();
        revStr(s,0,n);
    }
};