from functools import cache
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        coins.sort()
        @cache
        def traverse(ind, tar):
            if ind==0:
                if tar%coins[0]==0:
                    return tar// coins[0]
                return 1e9
            notPick=traverse(ind-1,tar)
            pick=1e9
            if coins[ind]<=tar:
                pick=1+traverse(ind,tar-coins[ind])
            return min(pick,notPick)
        ans=traverse(len(coins)-1,amount)
        if ans==1e9: 
            return -1
        else: return ans
            