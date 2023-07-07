//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<int> s;
        vector<int> lv(n,0);
        vector<int> rv(n,0);
        
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>=arr[i]) s.pop();
            if(s.empty()) lv[i] = 0;
            else lv[i] = s.top()+1;
            
            s.push(i);
        }
        
        
        while(!s.empty()) s.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]) s.pop();
            if(s.empty()) rv[i] = n-1;
            else rv[i] = s.top()-1;
            
            s.push(i);
        }
        
        
        int long long aremax = 0;
        for(int i=0;i<n;i++){
            int long long area = (rv[i]-lv[i]+1)*arr[i];
            aremax = max(aremax,area);
        }
        
        return aremax;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends