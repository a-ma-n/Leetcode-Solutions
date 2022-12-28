import heapq,numpy as np
class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        sortedPiles=list(np.array(piles)*-1)
        heapify(sortedPiles)
        while (k:=k-1)+1>0: heappush(sortedPiles, heappop(sortedPiles)//2)
        return -1*sum(sortedPiles)