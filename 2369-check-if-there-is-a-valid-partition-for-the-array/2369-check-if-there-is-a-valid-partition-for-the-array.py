class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        n=len(nums)
        @cache
        def recur(i):
            
            if i>=n: 
                # print(i)
                return True
            o1=o2=o3=False
            
            
            if i+1<n and i+2<n and nums[i]==nums[i+1]==nums[i+2]:
                # print(i+3,i)
                o1=recur(i+3)
            if i+1<n and i+2<n and nums[i]+2==nums[i+1]+1==nums[i+2]:
                # print(i+3,i)
                o2=recur(i+3)
            if i+1<n and nums[i]==nums[i+1]:
                # print(i+2,i)
                o3=recur(i+2)
            if o1 or o2 or o3:
                return True
            else:
                return False
            
        return recur(0)