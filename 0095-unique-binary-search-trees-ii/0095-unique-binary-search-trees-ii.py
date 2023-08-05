# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    @cache
    def allPossibleBST(self,start,end):
        res=[]
        if start>end: 
            res.append(None)
            return res
        
        for i in range(start,end+1):
            leftSubTrees = self.allPossibleBST(start,i-1)
            rightSubTrees = self.allPossibleBST(i+1,end)
            
            for left in leftSubTrees:
                for right in rightSubTrees:
                    root = TreeNode(i,left,right)
                    res.append(root)
        return res
    
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        return self.allPossibleBST(1,n)