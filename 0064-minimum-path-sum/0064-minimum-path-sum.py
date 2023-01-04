class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        # memoisation
        # @cache
        # def traverse(i,j):
        #     if i==len(grid) or j==len(grid[0]):return float(inf)
        #     if i==len(grid)-1 and j==len(grid[0])-1:return grid[i][j]
        #     return grid[i][j]+min(traverse(i+1,j),traverse(i,j+1))
        # return traverse(0,0)
        
        rows,cols=len(grid),len(grid[0])
        dp=[[0]*cols for _ in range(rows)]
        print(dp,grid[0][0])
        dp[0][0]=grid[0][0]
        print(dp)
        for i in range(1,rows):
            dp[i][0]=grid[i][0]+dp[i-1][0]
        for j in range(1,cols):
            dp[0][j]=grid[0][j]+dp[0][j-1]
        print(dp)
        for i in range(1,rows):
            for j in range(1,cols):
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1])
        print(dp)
        return dp[rows-1][cols-1]