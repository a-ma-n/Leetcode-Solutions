class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        nums.sort()
        i=j=maxSize=0
        maxVal=nums[0]
        minVal=nums[0]
        
        n=len(nums)
        
        while j<n:
            
            # minVal=min(minVal,nums[j])
            # maxVal=max(nums[i:j+1])
            
            if (nums[j]-nums[i])>(2*k) and i<j:#invalid
                # minVal=min(nums[i:j+1])
                # maxVal=max(nums[i:j+1])
                i+=1
            j+=1
            # else:
                # j+=1
            
            
            # print(i,j,maxVal-minVal>2*k)
            # j+=1
        return j-i