class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        
        def dfs(x, y, m, n, visit):
            if x < 0 or x >= m or y < 0 or y >= n:
                return False
            if grid[x][y] == 1 or visit[x][y]:
                return True
            visit[x][y] = True
            isClosed = True
            for k1,k2 in [[1,0],[-1,0],[0,1],[0,-1]]:
                r = x + k1
                c = y + k2
                if not dfs(r, c, m, n, visit):
                    isClosed = False
            return isClosed

        m = len(grid)
        n = len(grid[0])
        cnt=0
        visit = [[False] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 and not visit[i][j] and dfs(i,j,m,n,visit):
                    cnt+=1
        return cnt
