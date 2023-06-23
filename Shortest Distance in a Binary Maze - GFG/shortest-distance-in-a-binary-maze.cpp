//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        int si = source.first;
        int sj = source.second;
        int di = destination.first;
        int dj = destination.second;
        dist[si][sj] = 0;
        
        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{si,sj}});
        
        vector<int> dr = {0,0,1,-1};
        vector<int> dc = {1,-1,0,0};
   
        while(!pq.empty()){
            int disTillNow = pq.front().first;
            int i = pq.front().second.first;
            int j = pq.front().second.second;
            pq.pop();
            
            if(i == di && j == dj) return disTillNow;
            
            for(int k=0;k<4;k++){
                int ni = i+dr[k];
                int nj = j+dc[k];
                
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj] == 1){
                    if(disTillNow + 1 < dist[ni][nj]){
                       
                        dist[ni][nj] = disTillNow + 1;
                        pq.push({dist[ni][nj],{ni,nj}});
                    }
                }
            }
        }
        
        if(dist[di][dj] == 1e9) return -1;
        return dist[di][dj];
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends