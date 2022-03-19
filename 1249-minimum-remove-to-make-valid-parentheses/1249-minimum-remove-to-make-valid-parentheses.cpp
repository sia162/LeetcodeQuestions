class Solution {
public:
    string minRemoveToMakeValid(string s) {
//         stack<pair<char,int>> st;
//         int n = s.length();
        
//         for(int i=n-1;i>=0;i--){
//             if(s[i]==')') st.push({s[i],i});     
//             if(s[i]=='(')
//             st.size() and st.top().first==')'? st.pop(): st.push({s[i],i});  
//         }
        
        
//         string answer=""; answer.reserve(n);
//         for(int i=0;i<s.length();i++){
//             if(st.size() && st.top().second == i) st.pop();
//             else answer = answer + s[i];
//         }
        
//         return answer;
        
        
        int n= s.size();
        stack<pair<char,int>> st; 
        for(int i=n-1;i>=0;i--){
            if(s[i]==')') st.push({s[i],i});     
            if(s[i]=='(')
                st.size() and st.top().first==')'? st.pop(): st.push({s[i],i});            
        }


        string ans="";  ans.reserve(n);
        for(int i=0;i<n;i++)  
            if(st.size() and st.top().second==i) st.pop();   else ans+= s[i];

        return ans;
        }
};