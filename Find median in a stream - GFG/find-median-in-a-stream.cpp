//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    priority_queue<int> s; //maxheap
    priority_queue<int,vector<int>,greater<int>> g; //minheap
    //Function to insert heapg
    void insertHeap(int &x)
    {
        if(s.empty()==true || x<=s.top()){
            s.push(x);
        }
        
        else{
            g.push(x);
        }
        
        balanceHeaps();
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
         if(s.size()>g.size()+1){
            g.push(s.top());
            s.pop();
        }
        else if(s.size()<g.size()){
            s.push(g.top());
            g.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if (s.size() == g.size()) {
            return (s.top()+g.top())/2.0;
        } else {
            return s.top();
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends