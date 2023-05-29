//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
    void inordertrav(vector<int> A,int n,vector<int> &v,int i){
        if(i>=n) return;
        
        inordertrav(A,n,v,2*i+1);
        v.push_back(A[i]);
        inordertrav(A,n,v,2*i+2);
    }
    
    int minSwapsInVector(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>> v;
	    
	    for(int i=0;i<nums.size();i++){
	        v.push_back({nums[i],i});
	    }
	    
	    sort(v.begin(),v.end());
	    
	    int swapcount = 0;
	    for(int i=0;i<v.size();){
	        while(v[i].second!=i){
	            swap(v[i],v[v[i].second]);
	            swapcount++;
	        }
	        
	        i++;
	    }
	    
	    return swapcount;
	}
  
    int minSwaps(vector<int>&A, int n){
        //Write your code here
        vector<int> intrav;
        inordertrav(A,n,intrav,0);
        
        // for(int i=0;i<n;i++) cout<<intrav[i]<<" ";
        int ans = minSwapsInVector(intrav);
        
        return ans;
    }
    
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends