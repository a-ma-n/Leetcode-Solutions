class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        ans=[]
        sum=0
        for i in nums:
                if i%2==0:
                    sum+=i
                    
        for v,i in queries:
            if nums[i]%2==0:
                sum=sum-nums[i]
            nums[i]+=v
            if (nums[i])%2==0:
                sum=sum+nums[i]
            ans.append(sum)
        return ans
                