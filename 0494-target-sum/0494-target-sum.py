# https://takeuforward.org/data-structure/target-sum-dp-21/
from functools import cache
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        totSum=sum(nums)
        if (totSum-target)%2==1: return 0
        if totSum<target: return 0
        s2=(totSum-target)/2
        @cache
        def findSum(ind,target):
            if ind==0: 
                if target==0 and nums[0]==0: return 2
                if target==0: return 1
                return int(nums[0]==target)
            notPick=findSum(ind-1,target)
            pick=0
            if nums[ind]<=target:
                pick=findSum(ind-1,target-nums[ind])
            return pick+notPick
        return findSum(len(nums)-1,s2)
                