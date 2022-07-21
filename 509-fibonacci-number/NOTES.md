***memozation DP solution***
```
class Solution {
public:
int solveHere(vector<int> &dp,int n){
if(n<=1) return n;
if(dp[n]!=-1) return dp[n];
return dp[n] = solveHere(dp,n-1) + solveHere(dp,n-2);
}
int fib(int n) {
vector<int> dp(n+1,-1);
return solveHere(dp,n);
}
};
```