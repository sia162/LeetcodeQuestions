//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    // int solve(int i,int w,int wt[],int val[],vector<vector<int>>& dp){
    //     if(i < 0) return 0; 
    //     if(dp[i][w] != -1) return dp[i][w];
        
    //     int p = INT_MIN;
    //     if(wt[i]<=w) p = val[i] + solve(i-1,w-wt[i],wt,val,dp);
    //     int np = 0 + solve(i-1,w,wt,val,dp);
        
    //     return dp[i][w] = max(p,np);
    // }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code 
       vector<vector<int>> dp(n,vector<int> (W+1,0));
       
       for(int i=0;i<n;i++) dp[i][0] = 0;
       for(int j=0;j<=W;j++){
           if(j>=wt[0]) dp[0][j] = val[0];
       }
       
       for(int i=1;i<n;i++){
           for(int j=1;j<=W;j++){
               int  p = INT_MIN;
               if(wt[i]<=j) p = val[i] + dp[i-1][j-wt[i]];
               int np = 0 + dp[i-1][j];
               
               dp[i][j] = max(p,np);
           }
       }
       
       return dp[n-1][W];
    //   return solve(n-1,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends