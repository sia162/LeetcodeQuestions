class Solution {
public:
    bool isPalindrom(string s,int start,int end){
        while(end>=start){
            if(s[end]!=s[start]) return false;
            end--;
            start++;
        }
        
        return true;
    }
    
    void solvePar(int index,string s,vector<string> &seq,vector<vector<string>> &ans){
        if(index == s.length()){
            ans.push_back(seq);
            return;
        }
        
        
        for(int i=index;i<s.length();i++){
            if(isPalindrom(s,index,i)){
                seq.push_back(s.substr(index,i-index+1));
                solvePar(i+1,s,seq,ans);
                seq.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> seq;
        
        solvePar(0,s,seq,ans);
        return ans;
    }
};