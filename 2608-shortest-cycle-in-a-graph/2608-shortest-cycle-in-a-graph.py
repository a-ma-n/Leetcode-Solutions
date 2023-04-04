class Solution:
    def findShortestCycle(self, n: int, edges: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        minCycle = float('inf')
        for i in range(n):
            dist = [-1] * n
            q = deque()
            q.append(i)
            dist[i] = 0
            while q:
                u = q.popleft()
                for v in adj[u]:
                    if dist[v] == -1:
                        dist[v] = dist[u] + 1
                        q.append(v)
                    elif v != i and dist[v] >= dist[u]:
                        minCycle = min(minCycle, dist[u] + dist[v] + 1)

        return -1 if minCycle == float('inf') else minCycle