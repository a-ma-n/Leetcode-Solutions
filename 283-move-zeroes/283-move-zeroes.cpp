class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        stable_partition(begin(nums),end(nums),[](int i){return i;});
    }
};