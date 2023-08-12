class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        
        m=n=len(grid)
        
        @cache
        def recur(r,c):
            
            if not( 0<=r<m and 0<=c<n): return 1e9
            
            if r==m-1:
                return grid[r][c]
            
            
            return grid[r][c]+min(recur(r+1,c-1),recur(r+1,c),recur(r+1,c+1))
        
        minAns=1e9
        
        for j in range(n):
            minAns=min(minAns,recur(0,j))
            
            
        
        return minAns