class Solution {
public:
    bool checkInclusion(string p, string s) {
        
        vector<int> pcount(26,0);
        vector<int> scount(26,0);
        
        for(int i=0;i<p.length();i++){
            pcount[p[i]-'a']++;
        }
        
        int l=0;
        int r=0;
        int count = p.length();
        
        while(r<s.length()){
            scount[s[r]-'a']++;
            count--;
            r++;
            
            if(count == 0){
                if(pcount == scount) return true;
                
                if(r-l == p.length())
                {
                    scount[s[l]-'a']--;
                    l++;
                    count++;
                }
            }
           
        }
        return false;
    
    }
};