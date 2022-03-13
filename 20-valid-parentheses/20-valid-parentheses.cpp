class Solution {
public:
    bool isValid(string s) {
        
        if(s.length() < 2) return false;
        stack<char> st;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == ']' || s[i] == '}' || s[i] == ')'){
                if(st.empty()) return false;
                if(s[i] == ')' && st.top() != '(') return false;
                if(s[i] == ']' && st.top() != '[') return false;
                if(s[i] == '}' && st.top() != '{') return false;
                
                st.pop();
                
            }else st.push(s[i]);
        }
        
        if(!st.empty()) return false;
       
        return true;
    }
};