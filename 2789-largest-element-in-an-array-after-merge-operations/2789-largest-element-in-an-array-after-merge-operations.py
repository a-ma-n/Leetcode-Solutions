class Solution:
    def maxArrayValue(self, nums: List[int]) -> int:
        n=len(nums)
        s=nums[-1]
        for i in range(n-2,-1,-1):
            if nums[i]<=s:
                s+=nums[i]
            s=max(s,nums[i])
        return s
            