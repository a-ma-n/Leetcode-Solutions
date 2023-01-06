class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        coinsLeft=coins
        possibleIcecreams=0
        for cost in costs:
            if coinsLeft-cost<0: break
            print(coinsLeft,cost)
            coinsLeft-=cost
            possibleIcecreams+=1
        print(costs)
        return possibleIcecreams