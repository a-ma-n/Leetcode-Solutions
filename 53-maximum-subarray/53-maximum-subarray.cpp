class Solution {
public:
    int recur(vector<int>&nums,size_t n,int &max){
         if (n == 0) { max = nums[0]; return nums[0]; }
        int soFar = recur(nums,n-1,max);
        soFar = std::max(soFar+nums[n],nums[n]);// either we consider or we take the element we are standing at
        max = std::max(max,soFar);
        return soFar;
    }
    
    
    int maxSubArray(vector<int>& nums) {
        int res=0;
        //if(nums.size()==1) return nums[0];
        recur(nums,nums.size()-1,res);
        return res;
    }
};

    
    // int maxSubArray(vector<int>& nums, size_t n, int& max) {
    //     if (n == 0) { max = nums[0]; return nums[0]; }
    //     int soFar = maxSubArray(nums, n - 1, max);
    //     soFar = std::max(soFar + nums[n], nums[n]);
    //     max = std::max(max, soFar);
    //     return soFar;
    // }