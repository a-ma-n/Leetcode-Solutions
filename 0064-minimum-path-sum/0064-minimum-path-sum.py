class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        @cache
        def traverse(i,j):
            if i==len(grid) or j==len(grid[0]):return float(inf)
            if i==len(grid)-1 and j==len(grid[0])-1:return grid[i][j]
            return grid[i][j]+min(traverse(i+1,j),traverse(i,j+1))
        return traverse(0,0)