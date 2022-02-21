class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> ans(temps.size(),0);
        stack<pair<int,int>> st;
        
        // unordered_map<int,int> m;
        // for(int i=0;i<temps.size();i++) m[temps[i]] = i;
        
        for(int i=temps.size()-1;i>=0;i--){
            int curr = temps[i];
            
            if(st.empty()) ans[i]=0;
            else{
                while(!st.empty() && st.top().first<=curr){
                    st.pop();
                }
                
                if(!st.empty())
                    ans[i] = st.top().second - i;
                else
                    ans[i] = 0;
            }
            
            st.push({curr,i});
        }
      
        return ans;
    }
};