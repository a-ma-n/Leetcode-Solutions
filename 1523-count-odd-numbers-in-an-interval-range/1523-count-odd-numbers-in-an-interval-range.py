class Solution:
    def countOdds(self, low: int, high: int) -> int:         
        if low%2!=0:
            return len(range(low,high+1,2))
        else:
            return len(range(low+1,high+1,2))
            