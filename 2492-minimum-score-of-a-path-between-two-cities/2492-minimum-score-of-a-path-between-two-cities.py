from collections import defaultdict

class Solution:
    minCost=1e5+1
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        def dfs(visited,graph,node,cost,minCost):
            if node not in visited:
                visited.add(node)
                for neighbour in graph[node]:
                    dfs(visited,graph,neighbour,min(cost,roadValue[(node,neighbour)]),minCost)
            self.minCost=min(self.minCost,cost)
                
        
        graph=defaultdict(list)
        roadValue=dict()
        for i,j,score in roads:
            graph[i].append(j)
            graph[j].append(i)
            # print(graph[i],graph[j])
            
        for i,j,score in roads:
            roadValue[(i,j)]=score
            roadValue[(j,i)]=score
        print(graph)
            
        visited=set()
        dfs(visited,graph,1,1e4,1e4)
        
        return int(self.minCost) 