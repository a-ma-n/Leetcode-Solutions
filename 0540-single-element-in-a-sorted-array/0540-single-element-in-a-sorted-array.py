class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        low,high=0,len(nums)-1
        while low<=high:
            mid=low+(high-low)//2
            if mid==0 or mid==len(nums)-1: break
            if nums[mid]==nums[mid-1]:
                if (mid-low+1)%2!=0: high=mid
                else: low=mid+1
            elif nums[mid]==nums[mid+1]:
                if ((mid-1)-low-1)%2!=0: high=mid-1
                else: low=mid
            else: break
        return nums[mid]            