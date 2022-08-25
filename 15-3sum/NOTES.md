while(low<high && nums[low] == nums[low+1]) low++;
while(low<high && nums[high] == nums[high-1]) high--;
low++;
high--;
}else if(nums[low] + nums[high] > tofind){
high--;
}else{
low++;
}
}
}
}
​
return ans;