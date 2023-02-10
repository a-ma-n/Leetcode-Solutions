from collections import deque
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        rows,cols,steps=len(grid),len(grid[0]),0
        queue=collections.deque()
        for x in range(rows):
            for y in range(cols):
                if grid[x][y]==1:
                    queue.appendleft((x,y+1))
                    queue.appendleft((x,y-1))
                    queue.appendleft((x+1,y))
                    queue.appendleft((x-1,y))
        while queue:
            size=len(queue)
            steps+=1
            for k in range(size):
                x,y=queue[-1]
                queue.pop()
                if x>=0 and y>=0 and x<rows and y<cols and grid[x][y]==0:
                    grid[x][y]=steps
                    queue.appendleft((x,y+1))
                    queue.appendleft((x,y-1))
                    queue.appendleft((x+1,y))
                    queue.appendleft((x-1,y))
        # print("steps",steps)
        if steps==1:
            return -1 
        return steps-1
                                        
                    
                    
                
            
            