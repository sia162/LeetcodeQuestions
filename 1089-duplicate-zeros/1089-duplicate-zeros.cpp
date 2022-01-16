class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        // 1 0 2 3 0 4 5 0
            
        
        vector<int> ans;
        int i=0,n=arr.size();
        
        
        while(i<n){
            if(arr[i]!=0){
                ans.push_back(arr[i]);
            }else{
                ans.push_back(0);
                ans.push_back(0);
            }
            i++;
        }
        
        for(int i=0;i<n;i++){
            arr[i] = ans[i];
        }
    }
};