//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int array1[], int array2[], int n) {
            // code here 
        int low=0,high=n;
        
        while(low<=high){
            int cut1 = (low+high)>>1;
            int cut2 = n - cut1;
            
            int l1 = cut1 == 0 ? INT_MIN : array1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : array2[cut2-1];
            
            int r1 = cut1 == n ? INT_MAX : array1[cut1];
            int r2 = cut2 == n ? INT_MAX : array2[cut2];
            
            if(l1<=r2 && l2<=r1){
                return (max(l1,l2) + min(r1,r2));
            }else if(l1>r2){
                high = cut1-1;
            }else if(l2>r1){
                low = cut1+1;
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends