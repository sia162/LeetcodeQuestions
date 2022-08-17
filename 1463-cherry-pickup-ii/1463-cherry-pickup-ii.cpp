class Solution {
public:
//     int solvehere(vector<vector<int>>& g,int i,int j1,int j2,int n,int m,vector<vector<vector<int>>> &dp){
//         if(j1>=n || j2>=n || j1<0 || j2<0) return -1e9; //out of bound
//         if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
//         if(i == m-1){ //destination
//             if(j1==j2) return g[i][j1]; //in case same col
//             return g[i][j1] + g[i][j2]; // in case different col
//         }
//         if(j1 == j2) return g[i][j1];
//
//         //9 possible paths;
//         int maxi = -1e9;
//         for(int dj1 = -1;dj1 <= 1;dj1++){
//             for(int dj2 = -1; dj2 <= 1;dj2++){
//                 if(j1 == j2) maxi = max(maxi, g[i][j1] + solvehere(g,i+1,j1+dj1,j2+dj2,n,m,dp));
//                 else{
//                   maxi = max(maxi, g[i][j1] + g[i][j2] + solvehere(g,i+1,j1+dj1,j2+dj2,n,m,dp));  
//                 }
//             }
//         } 
//
//         dp[i][j1][j2] = maxi;
//         return maxi;
//     }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> front(m,vector<int>(m,-1));
        vector<vector<int>> curr(m,vector<int>(m,-1));
        
         
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1 == j2) front[j1][j2] = grid[n-1][j1];
                else front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    
                    int maxi = -1e9;
                    for(int dj1 = -1;dj1 <= 1;dj1++){
                        for(int dj2 = -1; dj2 <= 1;dj2++){
                            
                            int value = 0;
                            
                            if(j1 == j2) value = grid[i][j1];
                            else{
                              value = grid[i][j1] + grid[i][j2];
                            }
                            
                            if(j1+dj1 >=0 && j1+dj1<m && j2+dj2 >=0 && j2+dj2<m)
                                value += front[j1+dj1][j2+dj2];
                            else value += -1e8;
                                
                                
                            maxi = max(maxi,value);
                            
                        }
                    } 

                    curr[j1][j2] = maxi;
                }
            }
            
            front = curr;
        }
        
        return front[0][m-1];
    }
}; 