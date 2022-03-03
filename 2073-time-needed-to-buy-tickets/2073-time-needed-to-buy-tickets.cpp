class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
     
        int n = tickets.size();
        queue<pair<int,int>>q;
        int time=1;
        
        for(int i=0;i<n;i++) q.push({i,tickets[i]});
        
        while(!q.empty())
        {
            int index = q.front().first;
            int val = q.front().second;
            q.pop();
            val--;
            
            if(val==0 && index==k) return time;
            
            if(val!=0) q.push({index,val});
            time++; 
        }  
        
        return time;
    }
};