//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int M, int N, vector<vector<int>> Mat) {
        // code here
         int left = 0, right = N-1, top = 0, bottom = M-1;
        while(left < right && top < bottom){
            int prev = Mat[top+1][left];
            
            for(int i=left;i<=right;i++) swap(prev, Mat[top][i]);
            top++;
            
            for(int i=top;i<=bottom;i++) swap(prev, Mat[i][right]);
            right--;
            
            for(int i=right;i>=left;i--) swap(prev, Mat[bottom][i]);
            bottom--;
            
            for(int i=bottom;i>=top;i--) swap(prev, Mat[i][left]);
            left++;
        }
        return Mat;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(N, M, Mat);
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends