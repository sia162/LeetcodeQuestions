answer = s[i] + answer;
}
}
return answer;
***Approch  2 | Memory Limit***
​
int count = 0;
for(int i=0;i<s.length();i++){
if(s[i] == ')'){
if(count == 0){
s[i] = '#';
}else{
count--;
}
}else if(s[i] == '(') count++;
}
count = 0;
for(int i=s.length()-1;i>=0;i--){
if(s[i] == '('){
if(count == 0){
s[i] = '#';
}else{
count--;
}
}else if(s[i] == ')') count++;
}
string answer;
for(int i =0;i<s.length();i++){
if(s[i] == '#')
continue;
answer+=s[i];
}
return answer;
}
​