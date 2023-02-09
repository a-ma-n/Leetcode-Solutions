class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n=len(prices)
        
        @cache
        def transact(ind,buy):
            if ind>=n: return 0
            if buy:
                buy=-prices[ind]+transact(ind+1,0)
                notBuy=transact(ind+1,1)
                profit=max(buy,notBuy)
            else:
                sell=prices[ind]+transact(ind+2,1)
                dontSell=transact(ind+1,0)
                profit=max(sell,dontSell)
            return profit
        
        return transact(0,1)