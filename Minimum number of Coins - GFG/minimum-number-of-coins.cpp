//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> curr =  { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        int n = curr.size();
        int count = 0;
        
        vector<int> ans;
        
        for(int i=n-1;i>=0;){
            if(curr[i] > N){
                i--;
                continue;
            }else{
                int c = N/curr[i];
                count += c;
                while(c--) ans.push_back(curr[i]);
        
                N = N%curr[i];
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends