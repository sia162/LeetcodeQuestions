class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),[&](vector<int> &a, vector<int>&b){return a[1]<b[1];});
       
  
        int f = p[0][1];
        int arrow = 1;
        

        for(int i=1;i<p.size();i++){
            //if arrow lie in ballon range 
            //no need to waste a arrow
            //otherwise shot a arrow at x end point
            if( !(p[i][0]<=f && f<=p[i][1])){
                arrow++;
                f = p[i][1];
            }
        }
        
        return arrow;
    }
};