class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        # 2^1 = 3 => 1^3=2
        arr=list()
        res=first
        arr.append(first)
        for i in encoded:
            res=res^i
            arr.append(res)
        return arr
            