class Solution {
public:
    int dp[59][58];
    // 59,58 => 1 for safety n,n-1 (58+1,57+1)
    
    int solve(int n, int idx){
        
        if(n==0 || idx==0) return 1;
        
        if(dp[n][idx] != -1) return dp[n][idx];
        
        if(idx>n) return dp[n][idx] = solve(n,idx-1);
        
        return dp[n][idx] = max( idx*solve(n-idx,idx),solve(n,idx-1) );
    }
    int integerBreak(int n) {
        
        for(int rctr = 0 ; rctr <= 58 ; rctr++)
            for(int cctr = 0 ; cctr <= 57 ; cctr++)
                dp[rctr][cctr] = -1;
        
        return solve(n,n-1);
    }
};