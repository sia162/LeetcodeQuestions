class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(),boxTypes.end(), [](vector<int> &a,vector<int> &b)
        {
            return a[1] > b[1];
        });
        
        int ans = 0;
        int count = 0;
        
        for(int i=0;i<boxTypes.size();i++){
            count = count + boxTypes[i][0];
            
            
            if(count<=truckSize){
                ans = ans + boxTypes[i][0]*boxTypes[i][1];
            }
            else{
                count = count - boxTypes[i][0];
                ans = ans + (truckSize - count)*boxTypes[i][1];
                break;
            }
            
        }
             
        return ans;
        
    }
};