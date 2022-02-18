class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> m;
        vector<int> ans;
        
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            
            int val = st.empty()? -1 : st.top();
            m[nums2[i]] = val;
            
            st.push(nums2[i]);
        }
        
        for(auto ele: nums1){
            ans.push_back(m[ele]);
        }
       
        return ans;  
    }
};