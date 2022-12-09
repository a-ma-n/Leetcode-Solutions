# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    paths=[]
    maxDiff=0
    def backtrack(self,root,temp):
            if not root:
                return
            temp.append(root.val)
            if not root.left and not root.right:
                # self.paths.append(temp)
                self.maxDiff=max( self.maxDiff,abs(max(temp)-min(temp)) )
                # print(self.paths)
            self.backtrack(root.left,temp)
            self.backtrack(root.right,temp)
            temp.pop()
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        
        
        self.backtrack(root,[])
        
        # print("out",self.paths)
        # for path in self.paths:
        #     maxDiff=max( maxDiff,abs(max(path)-min(path)) )
        return self.maxDiff
                
        