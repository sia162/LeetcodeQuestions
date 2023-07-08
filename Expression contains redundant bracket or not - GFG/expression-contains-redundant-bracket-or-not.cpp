//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        int n = s.length();
        stack<char> st;
        
        for(int i=0;i<n;i++){
            if(s[i] == ')'){
                int cnt = 0;
                
                while(st.top() != '('){
                    cnt++;
                    st.pop();
                }
                
                if(cnt == 0) return true;
                st.pop();
            }else if(!isalpha(s[i])){
                st.push(s[i]);
            }
        }
        
        return false;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends