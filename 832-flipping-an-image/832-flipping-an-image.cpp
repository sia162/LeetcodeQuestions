class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
             // l   h    
        // [[1,1,0]
       // i // [0,1,0]
        // [0,0,0]]
        
        for(int i=0;i<image.size();i++){ //n
            for(int l=0,h=image[i].size()-1 ; l<=h ; l++,h--){ //n/2
                swap(image[i][l],image[i][h]);
                                
                if(image[i][l]) image[i][l] = 0;
                else image[i][l] = 1;
                
                if(l!=h){
                if(image[i][h]) image[i][h] = 0;
                else image[i][h] = 1;
                }
            }
        }
        
        return image;
    }
};