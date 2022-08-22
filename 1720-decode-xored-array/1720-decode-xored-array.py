class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        # 2^1 = 3 => 1^3=2
        res = [first]
        for a in encoded:
            res.append(res[-1]^a)
        return res