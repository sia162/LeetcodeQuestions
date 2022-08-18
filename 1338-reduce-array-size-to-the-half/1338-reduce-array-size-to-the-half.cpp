class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto v: arr) m[v]++;
        
        vector<pair<int,int>> v;
        for(auto it: m) v.push_back({it.first,it.second});
        
        sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b){
            return a.second>b.second;
        });
        
        
        int ans = 0;
        int count = 0;
        for(auto it: v){
            if(count >= arr.size()/2) return ans;
            count += it.second;
            ans++;
        }
        
        return ans;
        
    }
};