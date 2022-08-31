class Solution {
public:
    int minOperations(vector<int>& nums) {
        int c=0,diff=0;
        for(int i =0 ; i<nums.size()-1;i++){
            if(nums[i]>=nums[i+1]){
                diff=nums[i]-nums[i+1]+1;
                c+=diff;
                nums[i+1]+=(diff);
            }
        }
        return c;
    }
};