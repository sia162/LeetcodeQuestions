```
queue<int> q;
RecentCounter() {
}
int ping(int t) {
q.push(t);
long long int endlimit = t - 3000;
while(q.front() < endlimit)
q.pop();
return q.size();
}
```