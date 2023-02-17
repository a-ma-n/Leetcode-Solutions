# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        nodes=[]
        def t(root):
            if not root: return
            nodes.append(root.val)
            t(root.left)
            t(root.right)
        t(root)
        nodes.sort()
        minDiff=nodes[1]-nodes[0]
        for i in range(2,len(nodes)):
            minDiff=min(minDiff,nodes[i]-nodes[i-1])
        return minDiff