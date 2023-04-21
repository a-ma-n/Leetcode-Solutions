# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        def order(root):
            if not root: return 0
            
            left=order(root.left)
            right=order(root.right)
            
            level=max(left,right)+1
            dict[level].append(root.val)
            
            return level
        
        
        
        dict,res=defaultdict(list),[]
        order(root)
        for i in dict:
            res.append(dict[i])
        return res