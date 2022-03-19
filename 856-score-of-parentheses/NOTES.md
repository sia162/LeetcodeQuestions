**OLD Solutions**
```
int ans = 0;
pair<char,int> st;
st = {s[0],1};
for(int i=1;i<s.length();i++){
if(s[i] == '('){
st.second++;
}else if(s[i] == ')' && s[i-1] == '('){
ans = ans + pow(2,st.second - 1);
st.second--;
}else{
st.second--;
}
}
return ans;
```
​
​