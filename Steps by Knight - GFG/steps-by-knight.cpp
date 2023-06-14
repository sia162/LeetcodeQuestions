//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int bfs(int x,int y,int dx,int dy,vector<vector<int>>&vis){
        int n = vis.size();
        vis[x][y] = 1;
        int tm = INT_MAX;
        queue<pair<pair<int,int>,int>>q;
        q.push({{x,y},0});
        
        
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int tim = q.front().second;
            q.pop();
            vector<int>delx = {-2,-2,-1,1,2,2,-1,1};
            vector<int>dely = {-1,1,2,2,1,-1,-2,-2};
            
            for(int i=0;i<8;i++){
                int nx = x+delx[i];
                int ny = y+dely[i];
                
                if(nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    q.push({{nx,ny},tim+1});
                    
                    if(nx==dx && ny==dy) return tim+1;
                }
            }
        }
        
        return tm;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    int sx = KnightPos[0];
	    int sy = KnightPos[1];
	    int dx = TargetPos[0];
	    int dy = TargetPos[1];
	    if(sx==dx && sy==dy) return 0;
	    
	    vector<vector<int>>vis(n+1,vector<int>(n+1,0));
	    
	    int ans = bfs(sx,sy,dx,dy,vis);
	    
	    if(ans==INT_MAX) return -1;
	    return ans;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends