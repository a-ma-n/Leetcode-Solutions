class Solution {
public:
    // int f(int n,vector<int> &dp){
    //     if(dp[n]!=-1) return dp[n];
    //     if(n==0) return dp[n]=0;
    //     else if(n==1) return dp[n]=1;
    //     else{
    //         return dp[n]=f(n-1,dp)+f(n-2,dp);
    //     } 
    //    // return (n==0)?0:(n==1)?1:fib(n-1)+fib(n-2);
    // }
    int fib(int n) {
        if(n==0 || n==1) return n;
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        for(int i = 2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};