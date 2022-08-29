class Solution {
public:
    int minDistance(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n+1;i++) dp[i][0] = i;
        for(int j=0;j<m+1;j++) dp[0][j] = j;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(str1[i-1] == str2[j-1]) dp[i][j] = 0 + dp[i-1][j-1];
                else{
                    int c1 = 1 + dp[i][j-1]; //insert
                    int c2 = 1 + dp[i-1][j]; //delete
                    int c3 = 1 + dp[i-1][j-1]; //replace
                    dp[i][j] = min(c1,min(c2,c3));
                }
            }
        }

        return dp[n][m];
    }
};