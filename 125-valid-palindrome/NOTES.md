***non recursive approch***
```
int i=0,j=s.length()-1;
cout<<tolower(s[0]);
while(i<j){
while(!isalnum(s[i]) && i<j) i++;
while(!isalnum(s[j]) && i<j) j--;
if(tolower(s[i]) != tolower(s[j])) return false;
i++;j--;
}
return true;
```