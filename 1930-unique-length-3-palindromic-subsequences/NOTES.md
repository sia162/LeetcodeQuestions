**approch 1: 0(n^3)**
​
```
class Solution {
public:
bool checkpalindrome(string s){
for(int i=0,j=s.length()-1;i<=j;i++,j--){
if(s[i]!=s[j]) return false;
}
return true;
}
int countPalindromicSubsequence(string s) {
set<string> us;
for(int i=0;i<s.length();i++){
string seq = "";
seq += s[i];
for(int j=i+1;j<s.length();j++){
seq+=s[j];
for(int k=j+1;k<s.length();k++){
seq+=s[k];
if(checkpalindrome(seq))
us.insert(seq);
seq.pop_back();
}
seq.pop_back();
}
seq.pop_back();
}
return us.size();
}
};
```