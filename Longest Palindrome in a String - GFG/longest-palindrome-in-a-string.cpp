//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int n = s.size(),st = 0,e = 0;
        
        for(int i = 0;i < n;i++){
            
            //odd length
            int l = i,h = i;
            while(l >= 0 && h < n && s[l] == s[h]){
                if(e-st+1 < h-l+1) st = l,e = h;
                l--,h++;
            }
            
            //even length
            l = i,h = i+1;
            while(l >= 0 && h < n && s[l] == s[h]){
                if(e-st+1 < h-l+1) st = l,e = h;
                l--,h++;
            }
        }
        
        
        string ans = "";
        
        for(int i = st;i <= e;i++) ans.push_back(s[i]);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends