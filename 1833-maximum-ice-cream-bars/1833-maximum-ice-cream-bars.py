class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:     
         
        return sum(int((coins:=coins-cost)>=0) for cost in sorted(costs))
