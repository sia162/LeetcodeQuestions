class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        vector <int> p;
        vector<int> s(nums.size());
        
        int pro=1;
        for(int i=0;i<nums.size();i++){
            pro = pro*nums[i];
            p.push_back(pro);
        }
        
        pro=1;
        for(int i=nums.size()-1;i>=0;i--){
            pro = pro*nums[i];
            s[i]=pro;
        }
        
        for(int k=0;k<nums.size();k++){
            if(k == 0) ans.push_back(s[k+1]);
            else if(k == nums.size()-1) ans.push_back(p[k-1]);
            else{
                int i=k-1;
                int j=k+1;
                ans.push_back(p[i]*s[j]);
            }
        }
        return ans;
    }
};