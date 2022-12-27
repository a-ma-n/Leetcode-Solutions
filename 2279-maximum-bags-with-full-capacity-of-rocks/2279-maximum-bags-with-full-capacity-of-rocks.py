class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        differences=sorted([(cap-rock) for rock,cap in zip(rocks,capacity)])
        for index,diff in enumerate(differences):
            if additionalRocks<diff: return index
            additionalRocks-=diff
        return index+1