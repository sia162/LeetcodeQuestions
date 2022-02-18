vector<int> ans;
int found;
for(int i=0;i<nums1.size();i++){
found = 0;
auto it = find(nums2.begin(),nums2.end(),nums1[i]);
if(it!=nums2.end()){
int index = it - nums2.begin();
for(int j=index+1;j<nums2.size();j++){
if(nums2[j]>nums2[index]){
ans.push_back(nums2[j]);
found = 1;
break;
}
}
}
if(found==0)
{ans.push_back(-1);}
}
return ans;