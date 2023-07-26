//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    void solve(int i,string s,int k,string &ans){
        if(k==0) return;
        
        char maxnum = s[i];
        for(int idx=i+1;idx<s.length();idx++){
            if(maxnum<s[idx]){
                maxnum = s[idx];
            }
        }
        
        if(maxnum != s[i]){
            k--;
        } 
        
        for(int idx=i;idx<s.length();idx++){
            if(maxnum == s[idx]){
                swap(s[idx],s[i]);
                
                if(s.compare(ans) > 0) ans = s;
                solve(i+1,s,k,ans);
                
                swap(s[idx],s[i]);
            }
        }
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code her
       string ans = "";
       solve(0,str,k,ans);
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends