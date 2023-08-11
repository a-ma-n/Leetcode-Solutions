# from functools import cache
class Solution:
    # space optimised tabular form
    def change(self, amount: int, coins: List[int]) -> int:
        prev=[0]*(amount+1)
        cur =[0]*(amount+1)
        # dp=[[0]*(amount+1) for i in range(len(coins))]
        # target=0
        for target in range(amount+1):
            if target%coins[0]==0:
                prev[target]=1
                
        # shifting indexes by 1 
        # vat index -1 set val as 0
        
        for ind in range(1,len(coins)):
            for target in range(amount+1):
                notPick=prev[target]
                pick=0
                if coins[ind]<=target:
                    pick=cur[target-coins[ind]]
                cur[target]=pick+notPick
            prev=cur
        return prev[amount]
        
       