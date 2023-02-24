class Solution:
    def maxSumAfterPartitioning(self, nums: List[int], k: int) -> int:
        n=len(nums)
        @cache
        def f(ind):
            if ind == n: return 0
            l=0
            maxi,maxAns=-inf,-inf
            for j in range(ind,min(ind+k,n)):
                l+=1
                maxi=max(maxi,nums[j])
                sum=l*maxi+f(j+1)
                maxAns=max(maxAns,sum)
            return maxAns
        return f(0)
                