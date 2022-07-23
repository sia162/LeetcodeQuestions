class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int,int> m;
        int count = 0;
        int i,j;
        
        for(i=0,j=0;j<fruits.size();j++){
            m[fruits[j]]++;
            
            while(m.size()>2 && i<fruits.size()){
                m[fruits[i]]--;
                
                if(m[fruits[i]] == 0) m.erase(fruits[i]);
                i++;
           }
            count = max(count,j-i+1);
        }
        
        return count;
    }
};