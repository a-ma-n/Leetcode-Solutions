class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        
        # recursion:
        @cache
        def issafe(r,c):
            return 0<=r<m and 0<=c<n
        
        @cache
        def recur(r,c):
            if r==m-1 and c==n-1: return 1
            if not issafe(r,c): return 0
            
            return recur(r+1,c)+recur(r,c+1)
        
        return recur(0,0)
            