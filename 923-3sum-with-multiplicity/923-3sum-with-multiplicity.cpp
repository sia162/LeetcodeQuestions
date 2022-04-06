class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        long long int ans = 0;
        unordered_map<int,long> m;
        for(int i=0;i<arr.size();i++) m[arr[i]]++;
        
        for(auto v1:m){
            for(auto v2:m){
                int a = v1.first;
                int b = v2.first;
                int f = target - (a+b);
                
                if(!m.count(f)) continue;
                else if(a==b && b==f) ans += m[a]*(m[a]-1)*(m[a]-2) / 6;
                else if(a==b && b!=f) ans += m[a]*(m[a]-1)/2*m[f];
                else if(a<b && b<f) ans += m[a]*m[b]*m[f];
            }
        }
     
        
        return ans%(1000000007);
    }
};