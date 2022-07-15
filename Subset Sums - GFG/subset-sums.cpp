// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    void subsets(int i,vector<int> arr,int &sum,vector<int> &ans){
        if(i == arr.size()){
            ans.push_back(sum);
            return;
        }
        
        sum+=arr[i];
        subsets(i+1,arr,sum,ans);
        sum-=arr[i];
        subsets(i+1,arr,sum,ans);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> seq;
        vector<int> ans;
        // vector<vector<int>> s;
        int sum = 0;
        subsets(0,arr,sum,ans);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends