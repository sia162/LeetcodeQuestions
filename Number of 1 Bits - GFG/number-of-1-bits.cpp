//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    unsigned int countSetBits(int n){
        
        int count = 0;
        while(n){
            count += n&1;
            n=n>>1;
        }
        
        return count;
    }
  
    int setBits(int N) {
        // Write Your Code here
        return countSetBits(N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends