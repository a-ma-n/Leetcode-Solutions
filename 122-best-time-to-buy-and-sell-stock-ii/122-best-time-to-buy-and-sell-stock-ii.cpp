class Solution {
public:
    
    // TC: O(N)
    // SC: O(1) ~ O(5)
    int maxProfit(vector<int>& Arr) {
      
    int n = Arr.size();
    
   vector<vector<int>> dp(n+1,vector<int>(2,-1));
    
    //base condition
    dp[n][0] = dp[n][1] = 0;
    
    int profit;
    
    for(int ind= n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            if(buy==0){// We can buy the stock
                profit = max(0+dp[ind+1][0], -Arr[ind] + dp[ind+1][1]);
            }
    
            if(buy==1){// We can sell the stock
                profit = max(0+dp[ind+1][1], Arr[ind] + dp[ind+1][0]);
            }
            
            dp[ind][buy]  = profit;
        }
    }
    return dp[0][0];
}
};