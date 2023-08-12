class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        
        # recursion:
#         @cache
#         def issafe(r,c):
#             return 0<=r<m and 0<=c<n
        
#         @cache
#         def recur(r,c):
#             if r==m-1 and c==n-1: return 1
#             if not issafe(r,c): return 0
            
#             return recur(r+1,c)+recur(r,c+1)
        
#         return recur(0,0)
        
        # top down
        # initialise with 1 as there will alwyas be a way due to no obstruction
        
        
        dp=[[0]*n for _ in range(m)]
        
        dp[0][0]=1
        
        for i in range(1,m): dp[i][0]=1
        for j in range(1,n): dp[0][j]=1
            
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j]=dp[i-1][j]+dp[i][j-1]
        # print(dp)
        return dp[m-1][n-1]