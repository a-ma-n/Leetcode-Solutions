from functools import cache
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp=[[0]*(amount+1) for i in range(len(coins))]
        # target=0
        for target in range(amount+1):
            if target%coins[0]==0:
                dp[0][target]=1
                
        # shifting indexes by 1 
        # vat index -1 set val as 0
        
        for ind in range(1,len(coins)):
            for target in range(amount+1):
                notPick=dp[ind-1][target]
                pick=0
                if coins[ind]<=target:
                    pick=dp[ind][target-coins[ind]]
                dp[ind][target]=pick+notPick
        return dp[len(coins)-1][amount]
        
        # @cache
        # def getCoins(ind,target):
        #     if ind==0:
        #         return int(target%coins[0]==0)
        #     notPick=getCoins(ind-1,target)
        #     pick=0
        #     if coins[ind]<=target:
        #         pick=getCoins(ind,target-coins[ind])
        #     return notPick+pick
        # return getCoins(len(coins)-1,amount)