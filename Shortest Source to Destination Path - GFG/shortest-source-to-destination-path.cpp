//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0) return -1;
        
        vector<vector<int>> visit(N,vector<int>(M,0));
        visit[0][0]=1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int nrow=i+row[k];
                int ncol=j+col[k];
                
                if(nrow>=0 && nrow<N && ncol>=0 && ncol<M && A[nrow][ncol]!=0)
                {
                    if(visit[nrow][ncol]==0)
                    {
                        A[nrow][ncol] = A[i][j]+1;
                        visit[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                    else
                    {
                        if(A[nrow][ncol] > A[i][j]+1)
                        {
                            A[nrow][ncol] = A[i][j]+1;
                            q.push({nrow,ncol});
                        }
                    }
                    
                }
            }
        }
        return visit[X][Y]==1?A[X][Y]-1:-1;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends