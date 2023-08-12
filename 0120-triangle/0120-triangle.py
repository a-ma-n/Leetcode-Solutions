class Solution:
    def minimumTotal(self, grid: List[List[int]]) -> int:
        
        m=len(grid)
        
        @cache
        def recur(r,c):
            
            if not (0<=r<m and 0<=c<len(grid[r])): return 1e9
            
            if r==m-1:
                return grid[r][c]
            
            
            return grid[r][c]+min(recur(r+1,c),recur(r+1,c+1))
        
        return recur(0,0)