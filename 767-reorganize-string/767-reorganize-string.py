from collections import Counter
import heapq as q

# in python heap implemented as minheap => multiply the count by -1 if we want it to act as a maxheap
class Solution:
    def reorganizeString(self, s: str) -> str:
        
        heap = []
        counter = Counter(s)
        
        for k,v in counter.items():
            q.heappush(heap,(-v,k))
        
        res = ""
        while len(heap)>1:
            v1,k1 =q.heappop(heap)
            v2,k2 =q.heappop(heap)
            
            res += k1
            res += k2
            
            if abs(v1)>1:
                q.heappush(heap,(v1+1,k1))
            if abs(v2)>1:
                q.heappush(heap,(v2+1,k2))
        if heap:
            v,k = heap[0]
            if abs(v)>1:
                return ""
            else:
                res+=k
        return res
                          
            
    
            
        
        
        