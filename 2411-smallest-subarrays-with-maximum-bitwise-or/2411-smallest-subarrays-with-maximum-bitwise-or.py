class Solution:
    def smallestSubarrays(self, A: List[int]) -> List[int]:
        # bits in int(10^9)
        last = [0]*32
        n = len(A)
        res= [0] * n
        for i in range(n-1,-1,-1):
            for j in range(32): #O(1) tc
                if A[i] & (1<<j):# find if ith bit is set then mark the ith element
                    last[j]=i
            # masx(last) gives the position of the farthest set bit
            res[i]=max(1,max(last)-i+1)
        return res
        
    