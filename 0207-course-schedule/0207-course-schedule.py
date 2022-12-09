from collections import defaultdict

class Solution:
    
    def isCycle(self,adjacencyList,visited,id):
        if visited[id]==1:
            return True
        if visited[id]==0:
            visited[id]=1
            for edge in adjacencyList[id]:
                if self.isCycle(adjacencyList,visited,edge):
                    return True
        # after node is processed , mark it 2
        visited[id]=2
        return False
    
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adjacencyList=defaultdict(list)
        for edge in prerequisites:
            adjacencyList[edge[1]].append(edge[0])
        visited=[0]*numCourses
        for i in range(numCourses):
            if self.isCycle(adjacencyList,visited,i):
                return False
        return True
        
            
            