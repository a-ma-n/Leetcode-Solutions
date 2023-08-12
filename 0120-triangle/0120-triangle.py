class Solution:
    def minimumTotal(self, grid: List[List[int]]) -> int:
        
        m=len(grid)
        # recursion
        @cache
        def recur(r,c):
            
            if not (0<=r<m and 0<=c<len(grid[r])): return 1e9
            
            if r==m-1:
                return grid[r][c]
            
            
            return grid[r][c]+min(recur(r+1,c),recur(r+1,c+1))
        
        return recur(0,0)
    
        # bottom up
        m=len(grid)
        dp = [[0]*m for _ in range(m)]
        dp[0][0]=grid[0][0]
        for i in range(1,m):
            for j in range(len(grid[i])):
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i-1][j-1])
                
        # for i in range()
    
    