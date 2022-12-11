# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    maxi=float(-inf)
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def inorder(root):
            if  not root:
                return 0
            left=max(0,inorder(root.left))
            right=max(0,inorder(root.right))
            
            # pathsum=max(root.val+left+right,root.val,root.val+left,root.val+right,root.val)
            #print(pathsum)
            self.maxi=max(self.maxi,root.val+left+right)
            return root.val+max(left,right)
        inorder(root)
        return self.maxi
        