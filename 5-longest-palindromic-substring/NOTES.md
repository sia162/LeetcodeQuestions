**APPROCH 1 - brute force - 0(N^3) **
​
```
​
class Solution {
public:
bool checkPalindrome(string substr){
bool ans = true;
for(int i=0,j=substr.length()-1;i<=j;i++,j--){
if(substr[i]!=substr[j]) {ans = false; break;}
}
return ans;
}
string longestPalindrome(string s) {
// if(s.length() == 1) return s[0];
int maxlen = 0;
vector<string> substr;
for(int i=0;i<s.length();i++){
string str = "";
str = str + s[i];
substr.push_back(str);