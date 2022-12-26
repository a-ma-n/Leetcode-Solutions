import heapq
class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        sticksHeap=sticks
        heapq.heapify(sticksHeap)
        cost=0
        while len(sticksHeap)>1:
            temp=heapq.heappop(sticksHeap)+heapq.heappop(sticksHeap)
            print(temp)
            heappush(sticksHeap,temp)
            cost+=temp
            
        return cost
        