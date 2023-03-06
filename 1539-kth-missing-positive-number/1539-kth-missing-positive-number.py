class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        i=0
        while k>0:
            i+=1
            if i in arr: continue
            k-=1
            
        return i
        