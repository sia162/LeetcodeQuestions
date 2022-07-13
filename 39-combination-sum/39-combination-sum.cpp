class Solution {
public:
    void combinationSum(int i,vector<int> c,vector<int>& seq,vector<vector<int>>& combsum,int target){
        if(i>=c.size()){
           if(target == 0){
                combsum.push_back(seq);
            } 
            return;
        }
        
        if(c[i]<=target){
            seq.push_back(c[i]);
            combinationSum(i,c,seq,combsum,target-c[i]);
            seq.pop_back();
        }
   
        combinationSum(i+1,c,seq,combsum,target);
    }
     
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> seq;
        vector<vector<int>> combsum;
        
        combinationSum(0,candidates,seq,combsum,target);
        
        return combsum;
    }
};