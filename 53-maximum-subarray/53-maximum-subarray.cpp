class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>0)
                nums[i]+=nums[i-1];
            mx=max(mx,nums[i]);
        }
        return mx;
    }
};