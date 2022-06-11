**APPOCH WITHOUT BACKTRACKING**
​
```
class Solution {
public:
vector<string> ans;
​
void BalancedParanthesis(int o,int c,string op){
​
if(o==0 && c==0){
// cout<<op<<" ";
ans.push_back(op);
return;
}
​
string op1 = op;
string op2 = op;
​
if(o != 0){
op1.push_back('(');
BalancedParanthesis(o-1,c,op1);
}
​
if(c>o){
op2.push_back(')');
BalancedParanthesis(o,c-1,op2);
}
​
return;
}
​
vector<string> generateParenthesis(int n) {
int o,c;
o=n;c=n;
string op;
BalancedParanthesis(o,c,op);
return ans;
}
};
```
​
​
​