class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        
        @cache
        def recur(ind,lastVal):
            if ind<0:
                return 0
            red=costs[ind][0]+recur(ind-1,"red")
            blue=costs[ind][1]+recur(ind-1,"blue")
            green=costs[ind][2]+recur(ind-1,"green")
            
            if lastVal=="red":
                return min(blue,green)
            elif lastVal=="blue":
                 return min(red,green)
            elif lastVal=="green":         
                return min(blue,red)
            else:
                return min(red,blue,green)
            
        return recur(len(costs)-1,"temp")
    
        
        n=len(costs)
        dp=[[1e9]*3 for _ in range(n+1)]
        
        dp[0][0]=dp[0][1]=dp[0][2]=0
        dp[1][0]=costs[0][0]
        dp[0][1]=costs[0][1]
        dp[0][2]=costs[0][2]
        
        for i in range(2,n+1):
            dp[i][0]+=min(dp[i-1][1],dp[i-1][2])
            dp[i][1]+=min(dp[i-1][0],dp[i-1][2])
            dp[i][2]+=min(dp[i-1][0],dp[i-1][1])
        
        return min(dp[n][0],dp[n][1],dp[n][2])