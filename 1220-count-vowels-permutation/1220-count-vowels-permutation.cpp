class Solution { 
public:
    static const int a = 0, e = 1, i = 2, o = 3, u = 4, s = 5, MOD = 1e9 + 7;
    const vector<vector<int>> mapping = {{e}, // a ->
                                         {a, i}, // e -> 
                                         {a, e, o, u}, // i ->
                                         {i, u}, // o ->
                                         {a}, // u ->
                                         {a, e, i, u, o}}; // s ->
    int dp[20001][6] = {};
    
    
    int countVowelPermutation(int n, int last = s) {
        if (n == 0) return 1;
        if (dp[n][last]) return dp[n][last];
        int ans = 0;
        for (int nxt : mapping[last]) {
            ans = (ans + countVowelPermutation(n-1, nxt)) % MOD;
        }
        return dp[n][last] = ans;
    }
};