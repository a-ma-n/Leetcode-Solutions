class Solution:
    def sumOddLengthSubarrays(self, a: List[int]) -> int:
        n = len(a)
        res = 0
        for l in range(1,n+1,2):
            for i in range(n-l+1):
                res += sum(a[i:i+l])
        return res