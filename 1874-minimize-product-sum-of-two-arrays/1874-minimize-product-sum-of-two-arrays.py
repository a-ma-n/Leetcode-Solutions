class Solution:
    def minProductSum(self, nums1: List[int], nums2: List[int]) -> int:
        cpy1=sorted(nums1)
        cpy2=sorted(nums2,reverse=True)
        #mp=dict()
        sum=0
        for i in range(len(cpy2)):
            #mp[i]=j
            sum+=(cpy2[i]*cpy1[i])
        return sum