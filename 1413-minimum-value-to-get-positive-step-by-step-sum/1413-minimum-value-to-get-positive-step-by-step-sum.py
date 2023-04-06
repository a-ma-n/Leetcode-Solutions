class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        minV=1e9
        sumV=0
        for i in nums:
            sumV+=i
            minV=min(minV,sumV)
        if minV<1:
            return -1*minV+1
        else:
            return 1