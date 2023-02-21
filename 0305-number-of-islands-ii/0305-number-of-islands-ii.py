class Solution:
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        parent = {}
        def find(v):
            parent.setdefault(v,v)
            if parent[v] != v:
                parent[v] = find(parent[v])
            return parent[v]
        def union(v,w):
            pv, pw = find(v), find(w)
            parent[pv] = pw 
        res = []
        cur = 0
        visited = set()
        for i,j in positions:
            v = find((i,j))
            if v in visited: 
                res.append(cur)
                continue
            neis = set()
            for di,dj in [[-1,0],[1,0],[0,-1],[0,1]]:
                if 0<=i+di<m and 0<=j+dj<n and (i+di,j+dj) in visited:
                    neis.add(find((i+di, j+dj)))
                    union((i,j),(i+di,j+dj))
            if not neis:
                cur += 1
            else:
                cur -= len(neis) - 1
            res.append(cur)
            visited.add((i,j))
        return res