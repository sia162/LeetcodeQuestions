class Solution {
public:
//       int solvehere(int ind,vector<int>& coins,int tar,vector<vector<int>> &dp){
//         if(ind == 0){
//             if(tar%coins[ind] == 0) return 1;
//             else return 0;
//         }
          
//         if(dp[ind][tar] != -1) return dp[ind][tar];
        
//         int pick = 0;
//         if(coins[ind] <= tar) pick = solvehere(ind,coins,tar - coins[ind],dp);
//         int notpick = solvehere(ind-1,coins,tar,dp);
        
//         return dp[ind][tar] = pick + notpick;
//     } 
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        // vector<vector<int>> dp(n,vector<int> (amount+1,0));
        vector<int> prev(amount+1,0);
        
        for(int t=0;t<=amount;t++){
            if(t%coins[0] == 0) prev[t] = 1;
            else prev[t] = 0;
        }
        
        for(int i=1;i<n;i++){
            vector<int> curr(amount+1,0);
            
            for(int t=0;t<=amount;t++){
                int pick = 0;
                if(coins[i] <= t) pick = curr[t - coins[i]];
                int notpick = prev[t];

                curr[t] = pick + notpick;
            }
            
            prev = curr;
        }
        
        return prev[amount];
    }
};