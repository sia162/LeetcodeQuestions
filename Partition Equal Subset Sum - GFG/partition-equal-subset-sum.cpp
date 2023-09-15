//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int t,int arr[],vector<vector<int>> &dp){
        if(t == 0) return 1;
        if(i == 0) return t == arr[0];
        
        if(dp[i][t] != -1) return dp[i][t];
        
        int pick = 0;
        if(arr[i]<=t) pick = solve(i-1,t-arr[i],arr,dp);
        int notpick = solve(i-1,t,arr,dp);
        
        return dp[i][t] = pick || notpick;
    }

    int equalPartition(int N, int arr[])
    {
        // code here
        int s = 0;
        for(int i=0;i<N;i++){
            s+=arr[i];
        }
        
        if(s%2!=0) return 0;
        int target = s/2;
        
        vector<vector<int>> dp(N,vector<int>(target+1,0));
        
        for(int i=0;i<N;i++) dp[i][0] = 1;
        
        for(int i=1;i<N;i++){
            for(int t=0;t<=target;t++){
                int pick = 0;
                if(arr[i]<=t) pick = dp[i-1][t-arr[i]];
                int notpick = dp[i-1][t];
                
                dp[i][t] = pick || notpick;
            }
        }
        
        return dp[N-1][target];
        
        // return solve(N-1,target,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends