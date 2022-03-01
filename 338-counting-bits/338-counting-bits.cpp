class Solution {
public:
    
//     int binary(int n){
//         int count = 0;
        
//         while(n!=0){
//             if(n%2 == 1)
//             {
//                 count++;
//             }
//             n=n/2;
//         }
        
//         return count;
//     }
    
    
    vector<int> countBits(int n) {
        vector<int> ans;
        
        ans.push_back(0);
        for(int i=1;i<=n;i++)
        {
            int val = __builtin_popcount(i);
            ans.push_back(val);
        }
        
        return ans;
        
    }
};