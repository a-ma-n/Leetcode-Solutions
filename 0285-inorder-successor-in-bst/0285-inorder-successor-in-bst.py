# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderSuccessor(self, root: TreeNode, p: TreeNode) -> Optional[TreeNode]:
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
                