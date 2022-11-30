from collections import Counter
class Solution:
    def uniqueOccurrences(self, nums: List[int]) -> bool:
        return len(set(Counter(nums).values())) == len(set(nums))
