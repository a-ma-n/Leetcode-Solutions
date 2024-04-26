class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        # Save the size of the square grid
        n = len(grid)

        # Initialize a hash map to cache the result of each sub-problem
        memo = {}
        
        # The optimal(row, col) function returns the minimum sum of a 
        # falling path with non-zero shifts, starting from grid[row][col]
        def optimal(row, col):
            # If the last row, then return the value of the cell itself
            if row == n - 1:
                return grid[row][col]

            # If the result of this sub-problem is already cached
            if (row, col) in memo:
                return memo[(row, col)]

            # Select grid[row][col], and move on to next row. For next
            # row, choose the cell that leads to the minimum sum
            next_minimum = inf
            for next_row_col in range(n):
                if next_row_col != col:
                    next_minimum = min(next_minimum, optimal(row + 1, next_row_col))

            # Minimum cost from this cell
            memo[(row, col)] = grid[row][col] + next_minimum
            return memo[(row, col)]
        
        # We can select any element from the first row. We will select
        # the element which leads to minimum sum.
        answer = inf
        for col in range(n):
            answer = min(answer, optimal(0, col))
        
        # Return the minimum sum
        return answer