class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string> snums;
        for(int i=0;i<nums.size();i++){
            snums.push_back(to_string(nums[i])); 
        }
        
        sort(snums.begin(),snums.end(),[&](string a,string b) {
            return (a+b)>(b+a);
        });
        
        
        string ans="";
        for(auto s:snums) {
            if (ans.empty() && s == "0") return "0";
            ans+=s;
        }
        
        return ans;
    }
};