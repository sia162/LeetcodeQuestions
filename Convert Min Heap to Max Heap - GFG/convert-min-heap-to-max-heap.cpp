//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void heapify(vector<int> &arr,int i,int n){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        
        if(left<n && arr[left] > arr[largest]){
            largest = left;
        }
        
        if(right<n && arr[right] > arr[largest]){
            largest = right;
        }
        
        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify(arr,largest,n);
        }
    }

    void buildHeap(vector<int>& arr,int n){
        for(int i=n/2 - 1;i>=0;i--){
            heapify(arr,i,n);
        }
    }

    void convertMinToMaxHeap(vector<int> &arr, int N){
        buildHeap(arr,N);
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends