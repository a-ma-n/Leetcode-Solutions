from collections import defaultdict 

class Solution:
    flag=False
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        G=defaultdict(list)
        visited=set()
        for i,j in edges:
            G[i].append(j)
            G[j].append(i)
        print("S",source,"D",destination)
        def dfs(node):
            print(node)
            if node in visited:
                return
            if node == destination:
                print("found")
                self.flag=True
            visited.add(node)
            for neighbour in G[node]:
                dfs(neighbour)
            return 
        
        dfs(source)
        # print(flag)
        return self.flag