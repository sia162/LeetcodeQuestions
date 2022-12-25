//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        if(M>N) return -1;
        
        int sundays = S/7;
        int buyingdays = S-sundays;
        
        int totalneed = S*M;
        
        return totalneed%N == 0 ? (totalneed/N <= buyingdays? totalneed/N : -1) : (totalneed/N+1 <= buyingdays? totalneed/N+1 : -1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends