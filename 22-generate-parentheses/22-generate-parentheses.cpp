class Solution {
public:
    
    vector<string> ans;

    void BalancedParanthesis(int o,int c,string &s){
        if(o==0 && c==0){
            ans.push_back(s);
            return;
        }
        
        if(o>0){
            s.push_back('(');
            BalancedParanthesis(o-1,c,s);
            s.pop_back();
        }
        
        if(c>0){
            if(c>o){
                s.push_back(')');
                BalancedParanthesis(o,c-1,s);
                s.pop_back();
            }
        }
    }
    
    
    vector<string> generateParenthesis(int n) {
        int o,c;
        o=n;c=n;
        string s;
        BalancedParanthesis(o,c,s);
        return ans;
    }
};


