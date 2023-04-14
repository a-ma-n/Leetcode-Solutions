class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        
        #assume nums1 len > nums2 len
        if len(nums1)>len(nums2)*6 or len(nums1)*6<len(nums2):
            return -1
        sm1,sm2=map(sum,(nums1,nums2))
        
        if sm1>sm2:
            return self.minOperations(nums2,nums1)
        nums1.sort()
        nums2.sort()
        
        
        i,j = 0 , len(nums2)-1
        operations=0
        
        while sm2>sm1:
            if j<0 or i<len(nums1) and 6-nums1[i]>nums2[j]-1:
                sm1+=6-nums1[i]
                i+=1
            else:
                sm2-=nums2[j]-1
                j-=1
            operations+=1
        return operations
        
            