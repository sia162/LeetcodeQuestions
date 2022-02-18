class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        stack<string> st;
        st.push("main");
        
        for(int i=0;i<logs.size();i++){
            string operation = logs[i];
            
            if(st.top()!="main" && operation == "../"){
                st.pop();
            }else if(operation == "./"){
                //do nothing
            }else if(operation!="../" && operation!="./"){
                st.push(operation);
            }
        }
        
        
        return st.size()-1;
        
    }
};