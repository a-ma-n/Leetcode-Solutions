class Solution:
    def minimumMoney(self, A: List[List[int]]) -> int:
        res = v = 0
        for i,j in A:
            res+=max(0,i-j)
            v=max(v,min(i,j))
        return res + v
    