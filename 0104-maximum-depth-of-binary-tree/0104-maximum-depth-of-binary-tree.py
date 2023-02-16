# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    maxHeight=0
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        def t(root,h):
            # print(h)
            if not root: 
                # print("ht",self.maxHeight)
                self.maxHeight=max(self.maxHeight,h)
                return
            t(root.left,h+1)
            t(root.right,h+1)
        if not root: 
            return 0
        t(root,0)
        return self.maxHeight
        
            