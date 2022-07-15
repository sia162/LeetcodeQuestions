class Solution {
public:
    void combSumII(int index,vector<int> c,vector<int> &seq,vector<vector<int>> &ans,int target){
        if(target == 0){
            ans.push_back(seq);
            return;
        }    
         
        for(int j=index;j<c.size();j++){
            if(j>index && c[j] == c[j-1]) continue;
            if(c[j]>target) break;
            
            seq.push_back(c[j]);
            combSumII(j+1,c,seq,ans,target-c[j]);
            seq.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> seq;
        vector<vector<int>> ans;
        
        sort(candidates.begin(),candidates.end());
        combSumII(0,candidates,seq,ans,target);
        
        return ans;
    }
};