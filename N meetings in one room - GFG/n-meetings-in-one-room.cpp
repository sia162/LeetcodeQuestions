//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        
        vector<pair<int,int>> t;
        for(int i=0;i<n;i++) {
            t.push_back({start[i],end[i]});
        }
        
        sort(t.begin(),t.end(),[](pair<int,int> a,pair<int,int> b){
           return a.second<b.second; 
        });
        
        
        int endtime = 0;
        int ans = 0;
        for(auto p:t){
            if(p.first>endtime){
                endtime = p.second;
                ans++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends