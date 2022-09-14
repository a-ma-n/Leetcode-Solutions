class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
         # consider 3 first
        parents = {idx: idx for idx in range(1, n+1)}

        def find(x):
            if parents[x] != x:
                parents[x] = find(parents[x])
            return parents[x]
        
        def union(x, y):
            px, py = find(x), find(y)
            if px == py:
                return False
            else:
                parents[py] = px
                return True
        
        ans = 0
        cnt_a, cnt_b = 0, 0
        for t, u, v in edges:
            if t == 3:
                if union(u, v):
                    cnt_a += 1
                    cnt_b += 1 
                else:
                    ans += 1
        
        parents_copy = parents.copy()
        
        # alice
        for t, u, v in edges:
            if t == 1:
                if union(u, v):
                    cnt_a += 1
                else:
                    ans += 1  
                    
        parents = parents_copy.copy()
        for t, u, v in edges:
            if t == 2:
                if union(u, v):
                    cnt_b += 1
                else:
                    ans += 1
        return ans if cnt_a == cnt_b == n - 1 else -1