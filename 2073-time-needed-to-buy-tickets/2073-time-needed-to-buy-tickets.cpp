class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
     
        int n = tickets.size();
        int time = 0;
        
        int i=0;
        while(true){
            if(tickets[i]==0){
                i=(i+1)%n;
                continue;}
            
            time++;
            tickets[i]--;
            if(tickets[k]==0) return time;
            
            i=(i+1)%n;
        }
        
        return time;
    }
};