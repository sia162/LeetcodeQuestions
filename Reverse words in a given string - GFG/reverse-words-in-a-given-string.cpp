//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        
        for(int i=0;i<S.length();i++){
            int st=i;
            int e;
            while(i<S.length() && S[i]!='.') i++;
            e = i;
            
            if(st!=e) reverse(S.begin()+st,S.begin()+e);
        }
        
        reverse(S.begin(),S.end());
        
        return S;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends