//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int num) 
    {
        // Your code goes here  
        int s=0,e=num;
        long long int m = s + (e-s)/2;

        int ans;
        while(s<=e){
            long long int check = m*m;

            if(check>num) e=m-1;
            else{
                ans = m;
                s=m+1;
            }

             m = s + (e-s)/2;
        }

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
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends