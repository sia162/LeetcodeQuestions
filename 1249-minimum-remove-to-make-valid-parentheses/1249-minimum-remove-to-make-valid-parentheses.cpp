class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == ')'){
                if(!st.empty() && s[st.top()] == '('){
                    st.pop();
                }else{
                    s[i] = '#';
                }
            }else if(s[i] == '('){
                 st.push(i);
            }
        }
        
        while(!st.empty()){
            s[st.top()] = '#';
            st.pop();
        }
        
        string answer;
        for(int i =0;i<s.length();i++){
            if(s[i] == '#')
                continue;
            
            answer+=s[i];
        }
        
        return answer;
    }
};