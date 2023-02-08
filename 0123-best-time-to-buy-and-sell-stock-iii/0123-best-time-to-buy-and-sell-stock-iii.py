from functools import cache
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n=len(prices)
        @cache
        def buySell(ind=0,buy=0,cap=2):
            if ind==n  or cap==0:
                return 0
            
            if buy==0: #buy
                profit=max(-prices[ind]+buySell(ind+1,1,cap),buySell(ind+1,0,cap))
            else: #sell
                profit=max(prices[ind]+buySell(ind+1,0,cap-1),buySell(ind+1,1,cap))
            return profit
        return buySell()