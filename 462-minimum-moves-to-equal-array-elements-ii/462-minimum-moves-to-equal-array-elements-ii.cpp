class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int moves = 0, median = nums[size(nums)/2];
        for(auto it : nums) moves +=abs(it-median);
        return moves;
    }
};