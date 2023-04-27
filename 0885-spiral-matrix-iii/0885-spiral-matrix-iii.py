class Solution:
    def spiralMatrixIII(self, R: int, C: int, x: int, y: int) -> List[List[int]]:
        res = []
        dx, dy, n = 0, 1, 0
        while len(res) < R * C:
            for i in range(n // 2 + 1):
                if 0 <= x < R and 0 <= y < C:
                    res.append([x, y])
                x, y = x + dx, y + dy
            dx, dy, n = dy, -dx, n + 1
        return res