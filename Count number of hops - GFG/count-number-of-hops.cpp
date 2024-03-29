//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int mod = 1000000007;
    long long solve(int i,vector<long long>& dp){
        if(i == 0) return 1;
        if(i<0) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        long long one = solve(i-1,dp);
        long long two = solve(i-2,dp);
        long long three = solve(i-3,dp);
        
        return dp[i] = (one%mod + two%mod + three%mod)%mod;
    }
    
    long long countWays(int n)
    {
        // your code here
        vector<long long> dp(n+1,0);
        
        dp[0] = 1;
        
        for(int i=1;i<=n;i++){
            long long one = 0,two = 0,three = 0;
            if(i-1>=0) one = dp[i-1];
            if(i-2>=0) two = dp[i-2];
            if(i-3>=0) three = dp[i-3];
            
            dp[i] = (one%mod + two%mod + three%mod)%mod;
        }
        
        
        return dp[n];
        // return solve(n,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends