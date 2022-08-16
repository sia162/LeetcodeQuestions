class Solution {
public:
    int solvehere(vector<vector<int>>& g,int i,int j1,int j2,int n,int m,vector<vector<vector<int>>> &dp){
        if(j1>=n || j2>=n || j1<0 || j2<0) return -1e9; //out of bound
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        if(i == m-1){ //destination
            if(j1==j2) return g[i][j1]; //in case same col
            return g[i][j1] + g[i][j2]; // in case different col
        }
        if(j1 == j2) return g[i][j1];

        //9 possible paths;
        int maxi = -1e9;
        for(int dj1 = -1;dj1 <= 1;dj1++){
            for(int dj2 = -1; dj2 <= 1;dj2++){
                if(j1 == j2) maxi = max(maxi, g[i][j1] + solvehere(g,i+1,j1+dj1,j2+dj2,n,m,dp));
                else{
                  maxi = max(maxi, g[i][j1] + g[i][j2] + solvehere(g,i+1,j1+dj1,j2+dj2,n,m,dp));  
                }
            }
        }
        
        dp[i][j1][j2] = maxi;
        return maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<vector<int>>> dp(m , vector<vector<int>> (n, vector<int> (n,-1)));
        
        return solvehere(grid,0,0,n-1,n,m,dp);
    }
}; 