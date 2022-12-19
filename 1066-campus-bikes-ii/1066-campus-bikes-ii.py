class Solution:
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
        def dist(w,b):
            xw,yw=workers[w]
            xb,yb=bikes[b]
            return abs(xw-xb)+abs(yw-yb)
        @lru_cache(None)
        def dfs(used_bikes,wi):
            if wi == len(workers): return 0
            ans = float('inf')
            for bi in range(len(bikes)):
                if used_bikes & (bitmask := 1 << bi) == 0:
                    ans = min(ans, dist(wi, bi) + dfs(used_bikes | bitmask, wi+1))
            return ans         
        return dfs(0, 0) 