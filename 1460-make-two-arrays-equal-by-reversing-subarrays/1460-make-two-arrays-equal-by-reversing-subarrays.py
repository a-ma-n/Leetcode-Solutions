class Solution:
    def canBeEqual(self, target: List[int], A: List[int]) -> bool:
        return Counter(target) == Counter(A)