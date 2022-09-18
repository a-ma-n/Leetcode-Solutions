# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from queue import Queue


class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def rev(node1,node2,level):
            if node1 is None and node2 is None:
                return
            else:
                if (level%2)!=0:
                    node1.val,node2.val=node2.val,node1.val
                rev(node1.left,node2.right,level+1)
                rev(node1.right,node2.left,level+1)
        rev(root.left,root.right,1)
        return root
                    
            