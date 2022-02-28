class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        for(int i=0;i<nums.size();i++){
            
            string s;
            string e;
            string f = "";
            int found = 0;
            s = to_string(nums[i]);
            
            while(i<nums.size()-1 && nums[i+1] == nums[i]+1){
                e = to_string(nums[i+1]);
                found = 1;
                i++;
            }
            // cout<<e<<" "<<s<<endl;
            
            
            if(found == 1){ 
                f = s+"->"+e;
                ans.push_back(f);
            }
            
            //else
            if(found == 0 && i<nums.size()-1 && nums[i+1]!=nums[i]) ans.push_back(s);
            else if(found == 0 && i==nums.size()-1) ans.push_back(s);
        }
        
        return ans;
        
    }
};