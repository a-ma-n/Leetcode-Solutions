from functools import cache
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # coins.sort()
        n=len(coins)
        dp=[[0]*(amount+1) for i in range(n)]
        #base cases
        for i in range(amount+1):
            if i%coins[0]==0:
                dp[0][i]=i//coins[0]
            else:
                dp[0][i]=1e9
                
        for ind in range(1,n):
            for target in range(amount+1):
                notPick=dp[ind-1][target]
                pick=1e9
                if(coins[ind]<=target):
                    pick=1+dp[ind][target-coins[ind]]
                dp[ind][target]=min(pick,notPick)
                
        ans=dp[n-1][amount]
        if ans>=1e9:
            return -1
        else: 
            return ans
        
      