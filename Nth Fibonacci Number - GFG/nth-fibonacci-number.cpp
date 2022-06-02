// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        // code here
        int a = 0;
        int b = 1;
        int c,i;
        
        if(n==0) return a;
    
            for(i = 2; i <= n; i++)
            {
               c = (a%1000000007 + b%1000000007 )%1000000007;
               a = b;
               b = c;
            }
            
            return b;
        }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends