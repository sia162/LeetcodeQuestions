class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boat = 0,j,i;
        sort(people.begin(),people.end());
        
        for(i=0,j=people.size()-1;i<=j;){
            int sum = 0;
            
            if(i==j) 
               { boat++;
                break;}
            
            sum = people[i]+people[j];
            
            if(sum<=limit){
                i++;
                j--;
                boat++;
            }else if(people[i] >= people[j]){
                i++;
                boat++;
            }else{
                j--;
                boat++;
            }
        }
        return boat;
    }
};