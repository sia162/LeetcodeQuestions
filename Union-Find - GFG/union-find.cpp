//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to merge two nodes a and b.
    int findParent(int par[],int node)
    {
        if(node == par[node]) return node;
        return par[node] = findParent(par,par[node]);
    }
    
    void union_( int a, int b, int par[], int rank1[]) 
    {
        //code here
        int ulp_a = findParent(par,a);
        int ulp_b = findParent(par,b);
        
        if(ulp_a == ulp_b) return;
        else{
            if(rank1[ulp_a] > rank1[ulp_b]){
                par[ulp_b] = ulp_a;
            }else if(rank1[ulp_b] > rank1[ulp_a]){
                par[ulp_a] = ulp_b;
            }else{
                par[ulp_a] = ulp_b;
                rank1[ulp_b]++;
            }
        }
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[])
    {
        //code here
        int ulp_x = findParent(par,x);
        int ulp_y = findParent(par,y);
        
        return ulp_x == ulp_y;
    }
};

//{ Driver Code Starts.

int main() {
    //taking number of testcases
    int t;
    cin>>t;
    while(t--) {
        
        //taking number of elements
        int n;
        cin>>n;
        
        
        int par[n+1];
        int rank1[n+1];

        //initializing the parent and
        //the rank array
        for(int i=1; i<=n; i++) {
            par[i] = i;
            rank1[i] = 1;
    }
    
    //taking number of queries
    Solution obj;
    int q;
    cin>>q;
    while(q--) {    
        int a,b;
        char c;
        cin>>c>>a>>b;
        
        //if query type is 'U'
        //then calling union_ method
        if(c=='U')
        {
            obj.union_(a,b, par, rank1);
        }
        else//else calling isConnected() method
        cout<<obj.isConnected(a,b, par, rank1)<<endl;
    }
    }
    return 0;
}

// } Driver Code Ends