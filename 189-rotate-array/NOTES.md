​
// APPROCH 1
T - 0(N)  S-0(N)
//         vector<int> ans(nums.size(),0);
//         for(int i=0;i<nums.size();i++){
//             ans[(i+k)%nums.size()] = nums[i];
//         }
//         for(int i=0;i<nums.size();i++){
//             nums[i] = ans[i];
//         }
​
// APPROCH 2
T - 0(N)  S-0(1)
//             k = k % nums.size();
//             reverse(nums.begin(), nums.end());
//             reverse(nums.begin(), nums.begin() + k);
//             reverse(nums.begin() + k, nums.end());