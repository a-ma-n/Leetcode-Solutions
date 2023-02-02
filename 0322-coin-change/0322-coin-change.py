from functools import cache
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # coins.sort()
        n=len(coins)
        prev=[0]*(amount+1)
        cur=[0]*(amount+1)
        # dp=[[0]*(amount+1) for i in range(n)]
        #base cases
        for i in range(amount+1):
            if i%coins[0]==0:
                prev[i]=i//coins[0]
            else:
                prev[i]=1e9
                
        for ind in range(1,n):
            for target in range(amount+1):
                notPick=prev[target]
                pick=1e9
                if(coins[ind]<=target):
                    pick=1+cur[target-coins[ind]]
                cur[target]=min(pick,notPick)
            prev=cur
                
        ans=prev[amount]
        if ans>=1e9:
            return -1
        else: 
            return ans
        
      