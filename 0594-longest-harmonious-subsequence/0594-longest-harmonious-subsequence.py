class Solution:
    def findLHS(self, nums: List[int]) -> int:
        c=Counter(nums)
        maxLen=0
        for i in c:
            if i+1 in c:
                maxLen=max(maxLen,c[i]+c[i+1])
        return maxLen
    
    
    # def findLHS(self, A):
    # count = collections.Counter(A)
    # ans = 0
    # for x in count:
    #     if x+1 in count:
    #         ans = max(ans, count[x] + count[x+1])
    # return ans