class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        
        
        # recursion
        
        m,n=len(grid),len(grid[0])
        
        def issafe(r,c): return (0<=r<m and 0<=c<n)
        @cache
        def minPath(r,c):
            # print(r,c)
            if r==m-1 and c==n-1:
                return grid[m-1][n-1]
            
            if not issafe(r,c): return 1e9
            
            return grid[r][c]+min(minPath(r+1,c),minPath(r,c+1))
        return minPath(0,0)
    
    
        dp=[[1e9]*n for _ in range(m)]
        dp[0][0]=grid[0][0]
        
        for i in range(m):dp[i][0]=dp[i-1][0]+grid[i][0]
        for j in range(n):dp[0][j]=dp[0][j-1]+grid[0][j]
        
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j]= grid [i][j] + min(dp[i-1][j],dp[i][j-1])
        return dp[m-1][n-1]