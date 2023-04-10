class Solution:
    def findSubarrays(self, nums: List[int]) -> bool:
        sums=[]
        for i in range(1,len(nums)):
            sums.append(nums[i]+nums[i-1])
        print(sums,len(sums),len(set(sums)))
        return len(sums)!=len(set(sums))