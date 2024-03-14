class Solution {
public:
    // Number of subarrays with sum S = (no. of subarrays with sum atmost S ) - (no. of subarrays with sum as atmost S-1 )
    
    int atmost(vector<int>& nums, int goal){
    
    if (goal < 0)return 0;
        
    int i = 0, j = 0,sum=0,count=0,N=nums.size();
    
    for (; j < N; ++j) {
        sum+=nums[j];
        while (sum>goal)sum-=nums[i++];
        // why? count = size of the window
        count+=j-i+1;
    }
    return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal) - atmost(nums,goal-1);
    }
};