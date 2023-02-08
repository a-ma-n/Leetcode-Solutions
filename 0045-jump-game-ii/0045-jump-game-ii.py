from functools import cache
import sys
sys.setrecursionlimit(1000000)
class Solution:
    def jump(self, nums: List[int]) -> int:
        n=len(nums)

        @cache
        def traverse(ind):
            if ind>=n-1:
                return 0
            minJumps=1e9
            for i in range(1,nums[ind]+1):
                minJumps=min(minJumps,1+traverse(ind+i))
            return minJumps
        return traverse(0)