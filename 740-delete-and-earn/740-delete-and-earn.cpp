class Solution {
public:
    int dp[20001];
    int solve(vector<int>& nums, int pos){
        if(pos>=nums.size()) return 0;
        if(dp[pos]!=-1) return dp[pos];
        
        int cur = nums[pos];
        int sum = nums[pos];
        int idx = pos+1;
        
        //add all element which is equal to current element
        while(idx < nums.size() && nums[idx] == cur){
            sum+=nums[idx];
            idx++;
        }
        
        //skip all value which is equal to current value + 1;
        while(idx < nums.size() && nums[idx] == cur+1){
            idx++;
        }
        
        return dp[pos] = max(sum+solve(nums, idx), solve(nums, pos+1));
    }
    
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        memset(dp,-1,sizeof(dp));
        return solve(nums, 0);
    }
};