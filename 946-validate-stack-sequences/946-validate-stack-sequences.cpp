class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      
        stack<int> st;
        for(int i=0,j=0;i<pushed.size() || j<popped.size();i++){
            while(!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
            
            if(i>pushed.size() && st.top() != popped[j]) return false;
            if(i<pushed.size()) st.push(pushed[i]);
        }
        
        if(st.empty()) return true;
        return false;
    }
};