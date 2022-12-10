# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    total=0
    maxAnswer=0
    
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        mod=1e9+7
        def findTotal(root):
            if not root:
                return 0
            return (root.val+findTotal(root.left)+findTotal(root.right))%mod
            

        self.total=findTotal(root)
        print(self.total)
        
        def findproduct(root):
            if not root:
                return 0
            elif not root.left and not root.right:
                return root.val # to compare max val and get the sum
            
            # subchildSum=findTotal(root)
            left,right=findproduct(root.left),findproduct(root.right)
            subChildSum=(root.val+left+right)
            self.maxAnswer=max(self.maxAnswer, subChildSum*(self.total-subChildSum),left,right )
            return subChildSum
            
            # self.total-sumOfNodesEncountered
            # sumOfNodesE /ncountered=
            # return (max((subchildSum*(self.total-subchildSum)),findproduct(root.left,subchildSum,),findproduct(root.right,subchildSum)))%mod
        findproduct(root)
        return int(self.maxAnswer%mod)
