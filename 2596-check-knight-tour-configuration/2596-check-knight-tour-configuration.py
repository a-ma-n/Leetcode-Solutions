class Solution:
    def checkValidGrid(self, grid: List[List[int]]) -> bool:
        n = len(grid)
        visited = [[False] * n for _ in range(n)]
        directions = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]

        def backtrack(row, col, count):
            if count == n * n:
                return True
            for dx, dy in directions:
                new_row, new_col = row + dx, col + dy
                if 0 <= new_row < n and 0 <= new_col < n and not visited[new_row][new_col] and grid[new_row][new_col] == count:
                    visited[new_row][new_col] = True
                    if backtrack(new_row, new_col, count + 1):
                        return True
                    visited[new_row][new_col] = False
            return False

        if grid[0][0] != 0:
            return False
        visited[0][0] = True
        return backtrack(0, 0, 1)
