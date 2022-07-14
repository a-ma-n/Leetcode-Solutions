class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = 0;
        maxSubArray(nums, nums.size() - 1, res);
        return res;
    }
    
    int maxSubArray(vector<int>& nums, size_t n, int& max) {
        if (n == 0) { max = nums[0]; return nums[0]; }
        int soFar = maxSubArray(nums, n - 1, max);
        soFar = std::max(soFar + nums[n], nums[n]);
        max = std::max(max, soFar);
        return soFar;
    }
};