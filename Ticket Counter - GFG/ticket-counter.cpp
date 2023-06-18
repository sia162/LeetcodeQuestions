//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int k) {
        // code here
        deque<int> dq;
        
        for(int i=1;i<=N;i++){
            dq.push_back(i);
        }
        
        int tempk;
        for(int i=0;i<=N;i++){
            tempk = k;
            while(tempk--){
                if(dq.size() == 1) return dq.front();
                dq.pop_front();
            }
            
            tempk = k;
            while(tempk--){
                if(dq.size() == 1) return dq.front();
                dq.pop_back();
            }
            
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends