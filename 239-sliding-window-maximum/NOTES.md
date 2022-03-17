***APPROCH 1***
**T - 0(kN)**
```
int i=0,j=k-1;
vector<int> answer;
// T - 0(kN); --> 0(N^2) if N==k;
while(j<nums.size()){
int maxele = *max_element(nums.begin() + i,nums.begin() + j + 1);
answer.push_back(maxele);
i++;j++;
}
return answer;
```
​
**OPTIMIZED APPROCH 2 - using deque **
**T - 0(N)**
​
deque<int> dq;
vector<int> answer;
for(int i=0,j=0;j<nums.size();j++){
//popping all less values from deque
while(!dq.empty() && nums[dq.back()] < nums[j]) dq.pop_back();
dq.push_back(j);
//removing left element if window size increase
if(i > dq.front()) dq.pop_front();
//maintaining window size
if(j+1 >= k){
answer.push_back(nums[dq.front()]);
i++;
}
}
return answer;
**OPTIMIZED APPROCH 3 - using heap**
**T - 0(N)**