stack<char> st;
unordered_map<char,int> m{
{'(' , -1},{')' , 1},{'{' , -2},{'}',2},{'[',-3},{']',3}
};
​
for(int i=0;i<s.length();i++){
if(m[s[i]] < 0){
st.push(s[i]);
}else{
if(st.empty() || m[s[i]] + m[st.top()] != 0){
return false;
}
st.pop();
}
}
if(st.empty()){return true;}else{return false;}