**Recursion**
int rec(vector<int> &nums,int idx){
if(idx>=nums.size()) return 0;
return max(nums[idx]+rec(nums,idx+2),rec(nums,idx+1));
}
int rob(vector<int>& nums) {
}
**Memoization**
int rec(vector<int> &nums,int idx,vector<int> &dp){
if(idx>=nums.size()) return 0;
if(dp[idx]!=-1) return dp[idx];
return dp[idx]=max(nums[idx]+rec(nums,idx+2,dp),rec(nums,idx+1,dp));
}
int rob(vector<int>& nums) {
vector<int> dp(nums.size()+1,-1);
return rec(nums,0,dp);
}
**