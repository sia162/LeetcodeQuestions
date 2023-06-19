//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        int result = -1;
        
        while(low<=high){
            int m = low + (high-low)/2;
            
            int placedCows = k-1;
            int indexcurrcow = 0;
            for(int i=1;i<n;i++){
                if(stalls[i] - stalls[indexcurrcow] >= m){
                    placedCows--;
                    indexcurrcow = i;
                }
                
                if(placedCows == 0){ result = m; break;}
            }
            
            if(placedCows == 0) low = m+1;
            else high = m-1;
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends