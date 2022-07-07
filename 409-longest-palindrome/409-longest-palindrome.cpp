class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        
        for(int i=0;i<s.length();i++) m[s[i]]++;
        
        int mxl = 0;
        int ans = 0;
        bool one = false;
        for(auto v:m){
            
            // cout<<v.first<<" "<<v.second<<endl;
            if(v.second%2==0) ans = ans + v.second;
            else ans = ans + v.second-1;
            
            if(v.second%2!=0) one = true;
            mxl = max(mxl,v.second);
        }
        
        if(mxl%2!=0){
            ans = ans + 1;
        }
        
        if(mxl%2==0 && one) ans = ans+1;
        
        return ans;
    }
};