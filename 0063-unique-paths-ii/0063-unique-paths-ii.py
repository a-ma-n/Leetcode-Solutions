class Solution:
    def uniquePathsWithObstacles(self, grid: List[List[int]]) -> int:
        m,n=len(grid),len(grid[0])
        dp=[[0]*n for _ in range(m)]
        if grid[0][0]==0:dp[0][0]=1
        
        for i in range(m):
            if dp[i-1][0]==1 and grid[i][0]==0: dp[i][0]=1
        
        for j in range(n):
            if dp[0][j-1]==1 and grid[0][j]==0: dp[0][j]=1
                
        for i in range(1,m):
            for j in range(1,n):
                if grid[i][j]==0:
                    dp[i][j]=dp[i-1][j]+dp[i][j-1]
        print(dp)
        return dp[m-1][n-1]