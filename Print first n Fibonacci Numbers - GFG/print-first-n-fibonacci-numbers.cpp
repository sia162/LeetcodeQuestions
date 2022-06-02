// { Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    
    
    // int fibans(int n,vector<long long>& res){
    //     if(n < 2) return n;
    //     if(res[n - 1] != -1) return res[n - 1];
        
    //     return res[n-1] = fibans(n-1,res) + fibans(n-2,res);
    // }
    
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        //code here
        long long int res = 0, a = 1, b = 1;
        vector<long long> v;
        v.push_back(1);
        
        for(int i = 0; i < n-1; i++){
            res = a + b;
            a = b;
            b = res;
            v.push_back(a);
        }
        return v;
        
        
        
        
        // vector<long long> ans(n,-1);
        // ans[0] = 1;
        // fibans(n,ans);
        
        // return ans;
    }
};

// { Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}
  // } Driver Code Ends