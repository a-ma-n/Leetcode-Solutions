class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        def isPossible(x,y):
            return x>=0 and x<len(grid) and y>=0 and y<len(grid[0])
                
        def dfs(x,y):
            if grid[x][y]==0: 
                return
            grid[x][y]=0
            for k1,k2 in [[1,0],[-1,0],[0,1],[0,-1]]:
                new_x,new_y=x+k1,y+k2
                if isPossible(new_x,new_y):
                    dfs(new_x,new_y)
            return 
        
        
        
        cnt=0
        rows,cols=len(grid),len(grid[0])
        
        # print(grid)
        # iterate on the borders & remove them
        for i in range(rows):
            if grid[i][0]==1:
                dfs(i,0)
            if grid[i][cols-1]==1:
                dfs(i,cols-1)
        
        for c in range(cols):
            if grid[0][c]==1:
                dfs(0,c)
            if grid[rows-1][c]==1:
                dfs(rows-1,c)
                
        # print(grid)
        total=sum([ sum(row) for row in grid])
        
        return total