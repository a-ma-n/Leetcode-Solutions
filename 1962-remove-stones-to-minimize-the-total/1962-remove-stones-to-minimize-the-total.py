import heapq
class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        # print(list(cycle(piles)))
        itertools.product(piles,list([-1]*len(piles)))
        sortedPiles=[-1*i for i in piles]
        heapq.heapify(sortedPiles)
        while k>0:
            heappush(sortedPiles, heappop(sortedPiles)//2)
            k-=1
        return -1*sum(sortedPiles)
            
        