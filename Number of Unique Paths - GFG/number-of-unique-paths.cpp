//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int solve(int i,int j,vector<vector<int>> &dp){
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int t = solve(i-1,j,dp);
        int l = solve(i,j-1,dp);
        
        return dp[i][j] = t+l;
    }
    
    
    int NumberOfPath(int a, int b)
    {
        //code here
        vector<vector<int>> dp(a,vector<int>(b,0));
        
        dp[0][0] = 1;
        
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(i==0 && j==0) dp[0][0] = 1;
                else{
                    int t=0,l=0;
                    if(i-1>=0) t = dp[i-1][j];
                    if(j-1>=0) l = dp[i][j-1];
                    
                    dp[i][j] = t+l;
                }
            }
        }
        
        
        return dp[a-1][b-1];
        
        // return solve(a,b,dp);
        
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
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends