class Solution {
public:
    int dp[101][2];
    int rec(vector<int> &nums,int idx ,bool robFirst){
        if(idx>=nums.size() || (idx==nums.size()-1 && robFirst)) return 0;
        
        if(dp[idx][robFirst]!=-1) return dp[idx][robFirst];
        
        int rob=0,notRob=0;
        
        if(idx==0) rob=nums[idx]+rec(nums,idx+2,1);
        else rob=nums[idx]+rec(nums,idx+2,robFirst);
        notRob =  rec(nums,idx+1,robFirst);
        
        return dp[idx][robFirst]=max(rob,notRob);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof dp);
        //todo check how would i declare it if it were a 2d vector array
        return rec(nums,0,false);
    }
    
};