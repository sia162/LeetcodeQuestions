//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
        int count = 0;
        for(int i=0;i<n;i++){
            string s = arr[i];
            
            int found = 1;
            for(int j=0;j<k;j++){
                if(s[j] == str[j]) continue;
                else{
                    found = 0;
                    break;
                }
            }
            
            if(found) count++;
        }
        return count;
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
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends