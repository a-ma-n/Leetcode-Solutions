class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        # Define a recursive function to traverse the tree and sum up the numbers
        def dfs(node, path_sum):
            if not node:
                return 0
            # Add the current node's value to the path sum
            path_sum = path_sum * 10 + node.val
            # If this is a leaf node, return the path sum
            if not node.left and not node.right:
                return path_sum
            # Otherwise, recursively traverse the left and right subtrees
            return dfs(node.left, path_sum) + dfs(node.right, path_sum)
        
        # Call the recursive function on the root node with an initial path sum of 0
        return dfs(root, 0)