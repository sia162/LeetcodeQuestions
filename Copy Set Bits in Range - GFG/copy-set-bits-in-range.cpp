//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
//            A    = 10101010101
//      m1         = 00000000001
//  m1<<5          =  00000100000
// (m1<<5)-1       =  00000011111
// ((m1<<5)-1)<<2  =  00001111100 ===> m2
    
    
//         m2&A    =  00001010100
//            B    =  10010011001
//         ORing these two;
        
        
        int mask = 1 << (r-l+1);
        mask--;
        
        mask = (mask << (l-1));
        
        mask = (mask&y);
        
        x = x | mask;
        
        return x;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends