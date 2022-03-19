class Solution {
public:
    int scoreOfParentheses(string s) {
        
        int total = 0;
        stack<int> st;
        for(int i=0;i<s.length();i++){
          if(s[i] == '('){
              st.push(total);
              total = 0;
          }else{
              total = st.top() + max(total*2 , 1);
              st.pop();
          }
        }
        
        return total;
      
    }
};
