class Solution:
    def nimGame(self, piles: List[int]) -> bool:
        return reduce(operator.xor, piles)