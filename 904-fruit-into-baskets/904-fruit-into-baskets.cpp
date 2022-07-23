class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int,int> m;
        int count = 0;
        
        for(int i=0,j=0;j<fruits.size();j++){
            m[fruits[j]]++;
            
            while(m.size()>2 && i<fruits.size()){
                m[fruits[i]]--;
                
                if(m[fruits[i]] == 0) m.erase(fruits[i]);
                i++;
           }
            
            
            int newc = 0;
            for(auto it: m){
                newc += it.second;
            }
            
            count = max(count,newc);
        }
        
        return count;
    }
};