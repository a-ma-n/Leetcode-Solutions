class Solution {
public:
    // we execute this soln in such a way , that after incrementing i we make it equal to the size
  /*  bool solve(vector<int> &nums,int i,vector<int> dp){
        if(i == nums.size()) return true;
        if(i > nums.size()) return false;
        if(dp[i] != -1) return dp[i];
        
        if(i+1<nums.size() && nums[i]==nums[i+1]){
            // 2 elements are equal
            if(solve(nums,i+2,dp)) return true;
            // 3 elements are equal
            if(i+2<nums.size() && nums[i+1]==nums[i+2]){
                if(solve(nums,i+3,dp)) return true;
            }
        }
        // if nums[i]+2=nums[i+1]+1=nums[i]
        if(i+2 < nums.size() && nums[i]==nums[i+1]-1 && nums[i]==nums[i+2]-2)
            if(solve(nums,i+3,dp)) return true;
        // if none of the cases are satisfied then return false
        return dp[i]=false;
    }*/
    bool solve(vector<int>& nums, int i, vector<int>& dp){
        if(i == nums.size()) return true;
        if(i > nums.size()) return false;
        if(dp[i] != -1) return dp[i];
        
        if(i + 1 < nums.size() && nums[i] == nums[i+1] ) {
            if(solve(nums, i + 2, dp)) return true;
            if(i + 2 < nums.size() && nums[i] == nums[i+2]){
                if(solve(nums, i + 3, dp)) return true;
            }
        }
        if(i + 2 < nums.size() && nums[i] == nums[i+1]-1 && nums[i] == nums[i+2] - 2 ){
            if(solve(nums, i + 3, dp)) return true;
        }
        return dp[i] = false;
    }
    bool validPartition(vector<int>& nums) {
        // if size is 2 we check for this and return
        if(nums.size()==2) return nums[0]==nums[1];
        //declare a 1d dp & init to -1
        vector<int> dp(nums.size(),-1);
        // solve the dp by memoisation method
        return solve(nums,0,dp);
    }
};