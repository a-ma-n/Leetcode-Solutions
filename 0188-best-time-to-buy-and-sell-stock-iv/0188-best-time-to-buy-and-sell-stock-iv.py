class Solution:
    def maxProfit(self, k: int, Arr: List[int]) -> int:
        n=len(Arr)
        dp=[[[0]*(k+1) for i in range(2)] for j in range(n+1)]
        
        for ind in range(n-1,-1,-1):
            for buy in range(0,2):
                for cap in range(1,k+1):
                    if buy==0:
                        dp[ind][buy][cap] = max(0+dp[ind+1][0][cap], 
                                -Arr[ind] + dp[ind+1][1][cap])
                    if buy==1 :
                        dp[ind][buy][cap] = max(0+dp[ind+1][1][cap],
                                Arr[ind] + dp[ind+1][0][cap-1])
        return dp[0][0][k]
