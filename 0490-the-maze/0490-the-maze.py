class Solution:
    def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        m,n=len(maze),len(maze[0])
        stopped=set()
        
        def dfs(x,y):
            
            if (x, y) in stopped: 
                return False
            stopped.add((x, y))
            if [x, y] == destination:
                return True
            # stopped.add((x,y))
            
            for i, j in (-1, 0) , (1, 0), (0, -1), (0, 1):
                    newx,newy=x,y
                    while 0 <= newx+i < m and 0 <= newy+j < n and  maze[newx+i][newy+j] != 1:
                        newx+=i
                        newy+=j
                    if dfs(newx,newy):
                        return True
            return False
        
        return dfs(*start)