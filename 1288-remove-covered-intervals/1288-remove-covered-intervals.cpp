class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end() , [&](vector<int> &a, vector<int>&b){
            if(a[0] == b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        int intercount = 1;
        for(int i=1;i<intervals.size();i++){
            if(!(intervals[i][0]>=start && intervals[i][1]<=end)){
                intercount++;
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        return intercount;
    }
};