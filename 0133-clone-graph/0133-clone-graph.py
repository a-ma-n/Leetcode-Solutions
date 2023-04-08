"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def dfs(self, n, m, visited):
        
        if n in visited:
            return 
        visited.add(n)
        if n not in m:
            m[n] = Node(n.val)
        for neigh in n.neighbors:
            if neigh not in m:
                m[neigh] = Node(neigh.val)
            m[n].neighbors.append(m[neigh])
            self.dfs(neigh, m, visited)
            
    def cloneGraph(self, node: 'Node') -> 'Node':

        # return deepcopy(node)
        if not node:
            return node
        m, visited = dict(), set()
        self.dfs(node, m, visited)
        return m[node]


        