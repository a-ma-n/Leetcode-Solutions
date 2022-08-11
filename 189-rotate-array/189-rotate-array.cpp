class Solution {
public:
    
    
    void rotate(vector<int>& nums, int k) {
        k %=nums.size();
        // to take k elements from the back we need to do this
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};