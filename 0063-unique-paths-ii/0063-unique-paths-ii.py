class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        row,col=len(obstacleGrid),len(obstacleGrid[0])
        
        @cache
        def getNumberOfPaths(i,j):
            # print(i,j)
            if  i>=row or j>=col or obstacleGrid[i][j]==1 :
                return 0
            if i==row-1 and j==col-1: return 1

            return getNumberOfPaths(i,j+1)+getNumberOfPaths(i+1,j)
        
        return getNumberOfPaths(0,0)