class Solution {
public:
    // DP OPTIMISATION, check whether same state has already happened or not?
    bool already_happened(vector<int> sides,int pos){
        for(int i=0;i<pos;i++){
            if(sides[i]==sides[pos])
                return true;
        }
        return false;
    }
    // recursion
    bool recurse(vector<int> sides,int pos,int target,vector<int> v){
        // check if we reaches the target?
        if(pos==v.size())
            return sides[0]==target and sides[1]==target and sides[2]==target and sides[3]==target;
 
        for(int i=0;i<4;i++){
 
            // check whether on adding current matchstick length, increases the target?
            // also, check whether we have already checked this state or not?
            if(sides[i]+v[pos]>target or already_happened(sides,i))
                continue;
 
            // include current matchstick length
            sides[i]+=v[pos];
            if(recurse(sides,pos+1,target,v))
                return true;
 
            // reduce side length for further recursion
            sides[i]-=v[pos];
        }
        return false;
    }
    bool makesquare(vector<int>& sticks) {
        // sum of all matchsticks length
        int sum = accumulate(sticks.begin(),sticks.end(),0);
 
        // sorting in non-increasing order decreases the runtime as well as reduces the chance of TLE
        // since, bigger sticks are going to be processed at first
        sort(sticks.rbegin(),sticks.rend());
 
        // sides vector
        vector<int> sides(4,0);
 
        // if total sum of lengths of matchsticks is not a multiple of 4, we can't make a square 
        // also, there must be atleast 4 matchsticks
        if(sum%4 or sticks.size()<4)
            return false;
 
        // sum is now our target length = length of each side
        sum/=4;
 
        // also, check if any of the side has length more than the target, we can't make the matchstick
        if(sticks[0]>sum)
            return false;
 
        // recurse to find out if there exists any optimal square?
        return recurse(sides,0,sum,sticks);
    }
};