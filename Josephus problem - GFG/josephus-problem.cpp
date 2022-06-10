// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    void solvejose(vector<int> v,int k,int index,int& ans){
        if(v.size()==1){
            ans = v[0];
            return;
        }
        
        index = (index+k)%v.size();
        v.erase(v.begin()+index);
        
        solvejose(v,k,index,ans);
    }
    
    
    int josephus(int n, int k)
    {
       //Your code here
       vector<int> v;
       for(int i=0;i<n;i++){
           v.push_back(i+1);
       }
       
       int ans = -1;
       solvejose(v,k-1,0,ans);
       return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends