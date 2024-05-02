class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        # Sort the input list in ascending order
        nums.sort()

        lo = 0
        hi = len(nums) - 1

        while lo < hi:

            # If the negation of the element at lo is equal to the element at hi
            if -nums[lo] == nums[hi]:
                return nums[hi]

            # If the negation of element at lo is greater than element at hi
            elif -nums[lo] > nums[hi]: 
                lo += 1

            # If the negation of element at lo is smaller than element at hi
            else:
                hi -= 1

        return -1