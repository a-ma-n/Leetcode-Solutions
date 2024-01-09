# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def traverse(root,temp=[]):
            print(root)
            if not root:
                return
            traverse(root.left,temp)
            traverse(root.right,temp)
            if not root.left and not root.right:
                temp.append(root.val)
        sequence1,sequence2=[],[]
        traverse(root1,sequence1)
        traverse(root2,sequence2)
        print(sequence1,sequence2)
        return sequence1==sequence2
