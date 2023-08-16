//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int mod = 1e9 + 7;
class Solution
{
    public:
    
    int solve(int i,vector<int>& dp){
        if(i==0 || i==1) return 1;
        
        if(dp[i] !=-1) return dp[i];
        long long val=0;
        
        for(int j=0;j<i;j++)
        {
            val+=(1ll*solve(j,dp)*solve(i-j-1,dp))%mod;
        }
        
        return dp[i] = val%mod;
    }
    
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            long long val = 0;
            for(int j=0;j<i;j++){
                val+=(1ll*dp[j]*dp[i-j-1])%mod;
            }
            
            dp[i] = val%mod;
        }
        
        return dp[n]%mod;
        //  return solve(n,dp)%mod;
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends