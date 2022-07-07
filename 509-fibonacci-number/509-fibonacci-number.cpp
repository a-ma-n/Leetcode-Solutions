class Solution {
public:
    int f(int n,vector<int> &dp){
        if(dp[n]!=-1) return dp[n];
        if(n==0) return dp[n]=0;
        else if(n==1) return dp[n]=1;
        else{
            return dp[n]=f(n-1,dp)+f(n-2,dp);
        } 
       // return (n==0)?0:(n==1)?1:fib(n-1)+fib(n-2);
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};