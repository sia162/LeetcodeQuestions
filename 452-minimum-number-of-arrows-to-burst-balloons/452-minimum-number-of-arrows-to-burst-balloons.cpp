class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int arrow = 1;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        for(int i=0;i<points.size();i++) 
            p.push(make_pair(points[i][1],points[i][0]));
        
        auto it = p.top();
        int end = it.first;
        p.pop();
        
        auto itr = p.top();
        while(!p.empty()){
        
            while(!p.empty() && itr.second <= end){
                p.pop();
                
                if(p.empty()) break;
                itr = p.top();
            }
            
            if(p.empty()) break;
            end = itr.first;
            arrow++;
            p.pop();
            itr = p.top();  
        }
        
        return arrow;
    }
};