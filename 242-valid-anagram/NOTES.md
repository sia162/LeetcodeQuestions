```
class Solution {
public:
bool isAnagram(string s, string t) {
if(t.length()!=s.length()) return false;
unordered_map<char,int> m;
for(int i=0;i<t.length();i++){
m[t[i]]++;
m[s[i]]--;
}
for(auto count: m){
if(count.second) return false; //if count>0
}
return true;
}
};
```