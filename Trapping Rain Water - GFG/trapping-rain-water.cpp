//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
        // code here
        long long ans = 0;

        vector<int> prefixmax;
        vector<int> suffixmax(n,0);

        prefixmax.push_back(height[0]);
        suffixmax[n-1] = height[n-1];

        for(int i=1;i<n;i++){
            int val = max(prefixmax[i-1],height[i]);
            prefixmax.push_back(val);
        }


        for(int i=n-2;i>=0;i--){
            int val = max(suffixmax[i+1],height[i]);
            suffixmax[i] = val;
        }

        for(int i=0;i<n;i++) ans+=min(prefixmax[i],suffixmax[i]) - height[i];
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends