```
class Solution {
public:
int lengthOfLongestSubstring(string S) {
vector<int> lastindex(256,-1);
// vector<int> lastindex(26,-1);
int maxs = 0;
int i=0,j=0;
while(j<S.length() && i<S.length()){
if(lastindex[S[j]] + 1 > i){
i = lastindex[S[j]] + 1;
}
lastindex[S[j]] = j;
maxs = max(maxs,j-i+1);
j++;
}
return maxs;
}
};
```
​