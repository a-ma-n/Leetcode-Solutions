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