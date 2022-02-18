class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        for(int i=0;i<nums1.size();i++){
            stack<int> st;
            
            for(int j=nums2.size()-1;j>=0;j--) st.push(nums2[j]);
            while(st.top()!=nums1[i]){
                st.pop();
            }
            
            st.pop();
            while(!st.empty() && st.top()<nums1[i]){
                st.pop();
            }
            
            if(st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
        }
      
        return ans;  
    }
};