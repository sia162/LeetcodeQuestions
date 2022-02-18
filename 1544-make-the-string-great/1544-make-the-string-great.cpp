class Solution {
public:
    string makeGood(string s) {
        
        if(s=="") return s;
        stack<char> st;
         
        for(int i=0;i<s.length();i++){
            if(!st.empty() && (islower(s[i]) && toupper(s[i]) == st.top())){
                st.pop();
            }else if(!st.empty() && (isupper(s[i]) && tolower(s[i]) == st.top())){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};