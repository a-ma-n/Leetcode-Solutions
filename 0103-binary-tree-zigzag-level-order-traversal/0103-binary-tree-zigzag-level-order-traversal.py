# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root : return root
        q=deque()
        res=[]
        q.appendleft(root)
        leftToRight=True
        while q:
            size=len(q)
            row=[0]*(size)
            for i in range(size):
                node=q[-1]
                q.pop()
                if leftToRight:
                    idx=i
                else:
                    idx=(size-1-i)
                row[idx] = node.val
                if node.left:
                    q.appendleft(node.left)
                if node.right:
                    q.appendleft(node.right)
            leftToRight= not leftToRight
            res.append(row.copy())
        return res
                