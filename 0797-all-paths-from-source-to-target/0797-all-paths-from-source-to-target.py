class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        def dfs(node,path):
            print(node)
            if node==len(graph)-1:
                results.append(list(path))
                return
            for neighbour in graph[node]:
                path.append(neighbour)
                dfs(neighbour,path)
                path.pop()
        results=[]
        path=[0]    
        dfs(0,path)
        return results