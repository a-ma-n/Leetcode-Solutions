from functools import cache
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        @cache
        def getCoins(ind,target):
            if target==0: return 1
            if ind<0:    
                # print(target,)
                # if target%coins[0]==0: return target//coins[0]
                # # elif target==coins[0] : return 1
                return 0
            notPick=getCoins(ind-1,target)
            pick=0
            if coins[ind]<=target:
                pick=getCoins(ind,target-coins[ind])
            return notPick+pick
        return getCoins(len(coins)-1,amount)