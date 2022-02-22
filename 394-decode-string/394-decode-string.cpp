class Solution {
public:
    string decodeString(string s) {
      stack<char>st; string ans;
        
        for(int i=0;i<s.length();i++){
           if(s[i]==']'){
               string str,newstr;
               while(st.size()>0 && st.top()!='['){ //storing string inside square brackets
                   str+=st.top(); st.pop();
               }
               
               string num;
               if(st.size()) st.pop();
                   while(st.size()>0 && isdigit(st.top()) ){ //extracting number before bracket. It can be > 9, so we put loop to extract all digits
                       num+=st.top(); st.pop();
                   }           

               reverse(num.begin(),num.end()); //string inside bracket
               reverse(str.begin(),str.end()); //number before [
              int n=0;
               for(int i=0;i<num.length();i++){
                   n=n*10+ num[i]-'0';  //converting string to number
               }
               

               for(int i=0;i<n;i++) newstr+=str; //storing string by multiplying str k times in pb
               for(int i=0;i<newstr.length();i++) st.push(newstr[i]); //pushing back pb string because it can be inside another []
           }
            
            else st.push(s[i]); 
        }
        
        
        
     while(st.size()>0){ //popping out entire string in stack 
         ans+=st.top();
         st.pop();
     }   
        
        reverse(ans.begin(),ans.end()); //Reversing it to get ans
        return ans;
    }
};