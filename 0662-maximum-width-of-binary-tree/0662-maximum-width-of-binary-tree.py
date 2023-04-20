# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        
        if not root: return 0
        first_col_index_table = {}
        max_width = 0
        
        def DFS(root,depth,col_index):
            nonlocal max_width
            
            if not root: 
                return 
            
            if depth not in first_col_index_table:
                first_col_index_table[depth]=col_index
                
            max_width = max(max_width,col_index-first_col_index_table[depth] + 1)
            
            # Preorder DFS, with the priority on the left child
            DFS(root.left, depth+1, 2*col_index)
            DFS(root.right, depth+1, 2*col_index + 1)
        
        DFS(root, 0, 0)

        return max_width
            