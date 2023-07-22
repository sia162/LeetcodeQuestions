//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int arr[],int t,vector<vector<int>> &dp){
        if(t == 0) return 1;
        if(i<0) return 0;
        
        if(dp[i][t]!=-1) return dp[i][t];
        
        int nottake = solve(i-1,arr,t,dp);
        int take = 0;
        if(arr[i]<=t) take = solve(i-1,arr,t-arr[i],dp);
        
        return dp[i][t] = take || nottake;
    }

    int equalPartition(int N, int arr[])
    {
        // code here
        int s = 0;
        for(int i=0;i<N;i++) s+=arr[i];
        
        if(s%2!=0) return 0;
        
        int target = s/2;
        vector<vector<int>> dp(N,vector<int>(target+1,-1));
        
        return solve(N-1,arr,target,dp);
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