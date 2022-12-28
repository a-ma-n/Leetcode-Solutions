import heapq
import math
class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        sortedPiles=[-1*i for i in piles]
        heapq.heapify(sortedPiles)
        while k>0:
            temp=(heappop(sortedPiles)//2)
            heappush(sortedPiles,temp)
            k-=1
        return -1*sum(sortedPiles)
            
        