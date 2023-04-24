class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap=[-i for i in stones]
        heapify(heap)
        
        while len(heap)>1:
            # print(heap)
            a,b=heappop(heap),heappop(heap)
            if a==b: continue
            elif a<b:heappush(heap,a-b)
            else: heappush(heap,b-a)
                
        if heap:  return -heap[0]
        return  0
            