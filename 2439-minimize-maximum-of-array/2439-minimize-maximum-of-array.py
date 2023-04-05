class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        prefix_sum=ans=0
        for i,j in enumerate(nums):
            prefix_sum+=j
            ans=max(ans,math.ceil(prefix_sum/(i+1)))
        return ans