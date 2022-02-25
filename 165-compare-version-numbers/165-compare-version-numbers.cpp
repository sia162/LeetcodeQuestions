class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0;
        int j=0;
        
        int n1 = version1.size();
        int n2 = version2.size();
        
        string s1;int num1=0;
        string s2;int num2=0;
        
        while(i<n1 || j<n2){
            
            while(i<n1 && version1[i]!='.'){ s1.push_back(version1[i]); i++;}
            while(j<n2 && version2[j]!='.'){ s2.push_back(version2[j]); j++;}
            
            if(s1.length()!=0)
                num1 = stoi(s1);
            if(s2.length()!=0)
                num2 = stoi(s2);
            
            if(num1>num2) return 1;
            if(num2>num1) return -1;
            
            num1=0;
            num2=0;
            s1="";
            s2="";
            i++;
            j++;
            
        }
        
       return 0;
        
    }
};