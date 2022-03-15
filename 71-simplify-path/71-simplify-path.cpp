class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        string answer;
        
        for(int i=0;i<path.length();i++){
            if(path[i] == '/')
                continue;
            
            string s;
            while(i<path.length() && path[i] != '/'){
                s+=path[i];
                i++;
            }
            
            if(s == "."){
                //remain here only
                continue;
            }else if(s == ".."){
                if(!st.empty())
                    st.pop();
            }else{
                st.push(s);
            }
        }
        
        if(st.empty()){
            return "/";
        }
        
        while(!st.empty()){
            answer = "/" + st.top() + answer;
            st.pop();
        }
       
        return answer;
    }
};