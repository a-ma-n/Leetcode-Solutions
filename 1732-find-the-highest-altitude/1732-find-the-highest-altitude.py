class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        prefix=[0]
        for i in gain:
            prefix.append(prefix[-1]+i)
        return max(prefix)