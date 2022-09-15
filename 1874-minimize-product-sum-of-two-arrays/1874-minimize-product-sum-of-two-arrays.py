class Solution:
    def minProductSum(self, nums1: List[int], nums2: List[int]) -> int:
        
        return sum([i*j for i,j in zip(sorted(nums1),sorted(nums2,reverse=True))])
        