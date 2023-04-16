class Solution:
    def findPrefixScore(self, nums: List[int]) -> List[int]:
        m, conver = 0, []
        for x in nums:
            m = max(m, x)
            conver.append(x + m)
        return accumulate(conver)