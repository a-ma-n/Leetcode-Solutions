# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        
        graph=defaultdict(list)
        
        def traverse(root):
            if root.left:
                graph[root.val].append(root.left.val)
                graph[root.left.val].append(root.val)
                traverse(root.left)
                
            if root.right: 
                graph[root.val].append(root.right.val)
                graph[root.right.val].append(root.val)
                traverse(root.right)
        traverse(root)      
        # print(graph)
        # graph ready now time for bfs
        
        queue=deque([(start,0)])
        visited=set([start])
        time=0
        while queue:
            val,time=queue.popleft()
            for neighbour in graph[val]:
                if neighbour not in visited:
                    queue.append((neighbour,time+1))
                    visited.add(neighbour)
            # print(val,time,queue)
            # time+=1
        return time