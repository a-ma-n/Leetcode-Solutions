class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        
            n=len(nums)
            # missing=[]
            for i in range(1,n):
                # print(k)
                if k<=nums[i]-nums[i-1]-1:
                    return nums[i-1]+k
                else:
                    k-=(nums[i]-nums[i-1]-1)
                    

            
            return nums[n-1]+k
                
                
                