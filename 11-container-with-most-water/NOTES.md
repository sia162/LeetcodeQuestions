```
class Solution {
public:
int maxArea(vector<int>& height) {
int i=0;
int j=height.size()-1;
int currarea = 0;
int maxarea = 0;
while(i<j){
currarea = min(height[i],height[j]) * (j-i);
maxarea = max(maxarea,currarea);
if(height[i]<height[j]) i++;
else j--;
}
return maxarea;
}
};
```