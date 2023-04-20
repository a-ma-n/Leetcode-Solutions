"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""

class Solution:
    def inorderSuccessorOld(self, root: TreeNode, p: TreeNode) -> Optional[TreeNode]:
        ans=[]
        def inorder(node):
            if not node: return
            
            if node.left: inorder(node.left)
            # if p==node:
            ans.append(node)
            if node.right: inorder(node.right)
                
        inorder(root)
        for idx,j in enumerate(ans):
            if j==p and idx!=len(ans)-1:
                return ans[idx+1]
        return None
    
    def inorderSuccessor(self, node: 'Node') -> 'Optional[Node]':
        # if not node or node.parent==None: return None
        root=node
        while root.parent:
            # while parent:
            # temp=node
                root=root.parent
                # node=parent
        return self.inorderSuccessorOld(root,node)
