class Solution {
public:
    int lcs(string s, string t)
    {
        //Write your code here
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<n+1;i++) dp[i][0] = 0;
        for(int i=0;i<m+1;i++) dp[0][i] = 0;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 0 + max(dp[i-1][j] , dp[i][j-1]);
            }
        }

        return dp[n][m];
    //     return solvehere(n,m,s,t,dp);
    }
    
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(),s.end());
        
        return lcs(s,t);
    }
};