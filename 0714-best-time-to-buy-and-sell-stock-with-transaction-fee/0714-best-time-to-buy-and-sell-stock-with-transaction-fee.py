class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n=len(prices)
        @cache
        def transact(ind,buy):
            if ind==n: return 0
            if buy:
                buy=-prices[ind]+transact(ind+1,0)
                notBuy=transact(ind+1,1)
                profit=max(buy,notBuy)
            else:
                sell=prices[ind]+transact(ind+1,1)-fee
                dontSell=transact(ind+1,0)
                profit=max(sell,dontSell)
            return profit
        return transact(0,1)