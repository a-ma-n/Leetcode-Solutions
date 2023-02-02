from functools import cache
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        @cache
        def findWays(ind,target):
            if ind<0:
                if target==0:
                    return 1
                return 0
            subtract=findWays(ind-1,target+nums[ind])
            add=findWays(ind-1,target-nums[ind])
            return add+subtract
        return findWays(len(nums)-1,target)