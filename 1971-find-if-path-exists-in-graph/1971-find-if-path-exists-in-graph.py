from collections import defaultdict 

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        G=defaultdict(list)
        visited=set()
        for i,j in edges:
            G[i].append(j)
            G[j].append(i)
        def dfs(node):
            if node in visited: return
            if node == destination: return True
            visited.add(node)
            for neighbour in G[node]:
                if dfs(neighbour) : return True
            return False
        return dfs(source)
