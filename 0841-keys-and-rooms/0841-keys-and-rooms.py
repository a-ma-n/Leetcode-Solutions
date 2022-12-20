# from collections import defaultdict
class Solution:
    countOfNodes=0
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visited=set()
        def dfs(node):
            if node in visited : return
            visited.add(node)
            self.countOfNodes+=1
            print(self.countOfNodes,node)
            for neighbor in rooms[node]:
                dfs(neighbor)
                # countOfNodes
            return
        print(self.countOfNodes)
        dfs(0)
        return self.countOfNodes==len(rooms)