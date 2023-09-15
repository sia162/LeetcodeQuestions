//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        
        int t = 0;
        
        while(!q.empty()){
            int size = q.size();
            t++;
            
            for(int k=0;k<size;k++){
                
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                //travel directions
                for(int d=0;d<4;d++){
                    int newi = i+dr[d];
                    int newj = j+dc[d];
                    
                    if(newi>=0 && newi<n && newj>=0 && newj<m && grid[newi][newj] == 1){
                        grid[newi][newj] = 2;
                        
                        q.push({newi,newj});
                    }
                }
            }
        }
        
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
       
       if(t == 0) return 0;
       return t-1; 
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends