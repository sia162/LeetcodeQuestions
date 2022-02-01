class Solution {
public:
    
    int numOfeleSmallerThan(int num,int m,int n){
        int count = 0;
        
        for(int i=1;i<=m;i++){
            count += min(num/i,n);
        }
        
        return count;
    }
    
    
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m*n;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(numOfeleSmallerThan(mid,m,n)<k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return low;
    }
};