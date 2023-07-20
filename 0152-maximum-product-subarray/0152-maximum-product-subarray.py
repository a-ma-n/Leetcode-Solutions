class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        prod1=prod2=result=nums[0]
        n=len(nums)
        for i in range(1,n):
            temp = max(nums[i],prod1*nums[i],prod2*nums[i])
            prod2 = min(nums[i],prod1*nums[i],prod2*nums[i])
            prod1=temp
            
            result=max(result,temp)
        return result