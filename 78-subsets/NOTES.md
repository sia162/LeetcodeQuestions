if(ip.size()==0){
ans.push_back(op);
return;
}
vector<int> op1 = op;
vector<int> op2 = op;
op2.push_back(ip[0]);
ip.erase(ip.begin() + 0);
uniqueSubsets(ip,op1);
uniqueSubsets(ip,op2);
return;
}
vector<vector<int>> subsets(vector<int>& nums) {
vector<int> op;
uniqueSubsets(nums,op);
//         for(auto val : s){
//             ans.push_back(val);
//         }
return ans;