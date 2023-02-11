class Solution:
    def largestDivisibleSubset(self, arr: List[int]) -> List[int]:
        n=len(arr)
        arr.sort()
        dp=[1]*(n)
        hash=[1]*(n)
        for ind in range(n):
            hash[ind]=ind
            for prev_ind in range(0,ind):
                if arr[ind]%arr[prev_ind]==0 and 1+dp[prev_ind]>dp[ind]:
                    dp[ind]=1+dp[prev_ind]
                    hash[ind]=prev_ind
        ans,lastIndex=-1,-1
        for ind in range(n):
            if dp[ind]>ans:
                ans=dp[ind]
                lastIndex=ind
        temp=[]
        temp.append(arr[lastIndex])
        while hash[lastIndex]!=lastIndex:
            lastIndex = hash[lastIndex]
            temp.append(arr[lastIndex])   
        return reversed(temp)
        