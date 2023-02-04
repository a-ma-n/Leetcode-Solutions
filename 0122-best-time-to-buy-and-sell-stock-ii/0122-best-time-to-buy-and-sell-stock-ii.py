class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n=len(prices)
        dp=[[-1]*2 for i in range(n+1)]
        dp[n][0]=dp[n][1]=0
        
        for ind in range(n-1,-1,-1):
            for b in [0,1]:
                if b:
                    buy=-prices[ind]+dp[ind+1][0]
                    notBuy=dp[ind+1][1]
                    profit=max(buy,notBuy)
                else:
                    sell=prices[ind]+dp[ind+1][1]
                    dontSell=dp[ind+1][0]
                    profit=max(sell,dontSell)
                dp[ind][b]=profit
                print(ind,end=' ')
        return dp[0][1]