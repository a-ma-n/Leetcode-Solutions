class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp) ; 
    
    }
private:
    int f(int ind,int buy,vector<int> &prices,vector<vector<int>>&dp){
        // to prevent us from going out of bounds
        if(ind>=prices.size()) return 0;
        if(dp[ind][buy] !=-1) return dp[ind][buy];
        if(buy==1){
            return dp[ind][buy] = max(-prices[ind] + f(ind+1,0,prices,dp),
                       0 +f(ind+1,1,prices,dp));
        }
        // normally this should be the base case but, here since we have a condition for +2
        // ind = n-1
        return max(prices[ind]+f(ind+2,1,prices,dp),
                  0+f(ind+1,0,prices,dp));
    }
};