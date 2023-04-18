# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        if not nums:
            return None
        stack = []  #build a decreasing stack
        for i in nums:
            node = TreeNode(i)
            lastpop = None
            
            while stack and stack[-1].val < i:  #popping process
                lastpop = stack.pop()
            node.left = lastpop
            
            if stack:
                stack[-1].right = node
            stack.append(node)
            
        return stack[0]