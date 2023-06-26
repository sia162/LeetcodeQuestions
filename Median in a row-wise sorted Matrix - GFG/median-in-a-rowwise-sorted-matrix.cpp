//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &mat, int R, int C){
        // code here       
        
        int mn = 0,mx = 0,d = (R*C+1)/2;
        for(int i = 0;i < R;i++){
            mn = min(mn,mat[i][0]);
            mx = max(mx,mat[i][C-1]);
        }
        
        while(mn < mx){
            int md = (mn+mx)/2,c = 0;
            for(int i = 0;i < R;i++) c += upper_bound(mat[i].begin(),mat[i].end(),md)-mat[i].begin();
            if(d > c) mn = md+1;
            else mx = md;
        }
        
        return mn;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends