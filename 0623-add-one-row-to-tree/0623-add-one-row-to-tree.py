# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # BFS
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        if not root:
            return root
        if d==1:
            return TreeNode(v, root, None)

        q = [root]
        prev_level = []
        l = 0
        while q:
            size = len(q)
            l +=1
            if l==d-1:
                prev_level = q
                break
            while size:
                front = q.pop(0)
                size-=1
                if front:
                    q.append(front.left)
                    q.append(front.right)             
        while prev_level:
            r = prev_level.pop()
            if r:
                ln = TreeNode(v, r.left, None)
                rn = TreeNode(v, None, r.right)
                r.left, r.right = ln, rn

        return root