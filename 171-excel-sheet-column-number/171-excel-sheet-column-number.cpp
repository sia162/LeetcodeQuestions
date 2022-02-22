class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long int alphaorder=1;
        long long int ans=0;
        
        for (int i=columnTitle.size()-1;i>=0;i--)
        {
            ans+=(columnTitle[i]-'A'+1)*alphaorder;
            alphaorder=alphaorder*26;
        }
        return ans;
    }
};