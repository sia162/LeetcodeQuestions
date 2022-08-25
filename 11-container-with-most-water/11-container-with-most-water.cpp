class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int area = -1e9;
        for(int i=0,j=height.size()-1;i<j;){
            area = max(area, min(height[i],height[j]) * (j-i));
            
            if(height[i]<height[j]) i++;
            else j--;
        }
        
        return area;
    }
};