import sys
sys.setrecursionlimit(200000)
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxJump,n=0,len(nums)
        for i,x in enumerate(nums):
            if maxJump<i: return False
            if maxJump>=n-1: return True
            maxJump=max(i+x,maxJump)
            
