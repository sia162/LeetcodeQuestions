//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void insert_at_bottom(stack<int>& s,int x){
        if(s.empty()){
            s.push(x);
            return;
        }
        
        int emp = s.top();
        s.pop();
        insert_at_bottom(s,x);
        s.push(emp);
        return;
        
    }

    void reverse(stack<int>& st)
    {
        if (st.size() > 0) {
            int x = st.top();
            st.pop();
            
            reverse(st);
            insert_at_bottom(st, x);
        }
        return;
    }
        
    void Reverse(stack<int> &St){
        reverse(St);
        return;
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends