import heapq
class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        sortedPiles=[-1*i for i in piles]
        heapq.heapify(sortedPiles)
        while (k:=k-1)+1>0:
            print(k)
            heappush(sortedPiles, heappop(sortedPiles)//2)
        print(sortedPiles)
        return -1*sum(sortedPiles)
            
        