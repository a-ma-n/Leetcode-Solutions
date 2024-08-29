class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        def dfs(node):
            nonlocal moves
            visited.add(node)
            for next_node in graph[node]:
                if next_node not in visited:
                    moves += 1
                    dfs(next_node)
        graph , moves , visited = defaultdict(list) , 0 , set()
        for i in range(len(stones)):
            for j in range(i):
                if stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]:
                    graph[i].append(j)
                    graph[j].append(i)
        for node in range(len(stones)):
            if node not in visited:
                dfs(node)
        return moves