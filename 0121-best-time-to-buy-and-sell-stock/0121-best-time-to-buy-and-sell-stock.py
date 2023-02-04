class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxProfit=0
        minPrice=prices[0]
        for price in prices:
            if price<minPrice:
                minPrice = price
                continue
            profit=price - minPrice
            if profit>maxProfit:
                maxProfit=profit
        return maxProfit