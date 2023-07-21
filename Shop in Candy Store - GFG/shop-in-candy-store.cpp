//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N);
        
        int minp = 0;
        for(int i=0,j=N-1;i<N && i<=j;i++){
            minp += candies[i];
            j = j - K;   
        }
        
        int maxp = 0;
        for(int i=N-1,j=0;i>=0 && j<=i;i--){
            maxp += candies[i];
            j = j + K;
        }
        
        return {minp,maxp};
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends