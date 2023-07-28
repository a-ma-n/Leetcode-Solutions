class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        
        n = len(nums)
        
        def maxDiff(l,r):
            if l==r:
                return nums[l]
            
            part1= nums[l] - maxDiff(l+1,r)
            part2= nums[r] - maxDiff(l,r-1)
            
            return max(part1,part2)
        
        return maxDiff(0,n-1)>=0