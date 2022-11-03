class Solution {
public:
    int maxArea(vector<int>& height) {
        int areamax = INT_MIN;
        
        for(int i=0,j=height.size()-1;i<j;){
            int a = (j-i)*(min(height[i],height[j]));
            areamax = max(areamax, a);
            
            if(height[i]<height[j]) i++;
            else j--;
        }
        
        return areamax;
    }
};