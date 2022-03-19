***Approch 1 | Memory Limit***
​
stack<pair<char,int>> st;
for(int i=0;i<s.length();i++){
if(s[i] == ')'){
if(!st.empty() && st.top().first == '('){
st.pop();
}else{
st.push({s[i],i});
}
}else if(s[i] == '('){
st.push({s[i],i});
}
}
string answer;
for(int i=s.length()-1;i>=0;i--){
if(!st.empty() && st.top().second == i){
st.pop();
continue;
}else{
answer = s[i] + answer;
}
}
return answer;
***Approch  2 | Memory Limit***
​
​