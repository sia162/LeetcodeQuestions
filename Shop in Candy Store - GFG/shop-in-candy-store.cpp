//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int k)
    {
        // Write Your Code here
       sort(candies, candies + N);
        
        int costmin = 0;
        int costmax = 0;
        for(int i=0,j=N-1;i<=j;i++){
            costmin = costmin + candies[i];
            j = j-k;
        }
        
        for(int i=N-1,j=0;j<=i;i--){
            costmax = costmax + candies[i];
            j = j+k;
        }
        
        return {costmin,costmax};
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