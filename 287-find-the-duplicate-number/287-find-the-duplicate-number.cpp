class Solution {
public:
    //aproach 3 in solns
    int findDuplicate(vector<int>& nums) {
     
    for(int i=0;i<nums.size();i++){
        auto val=abs(nums[i]);
        if(nums[val]<0){
            return val;
        }
        nums[val]*=-1;
    }
        return 0;
    }
};