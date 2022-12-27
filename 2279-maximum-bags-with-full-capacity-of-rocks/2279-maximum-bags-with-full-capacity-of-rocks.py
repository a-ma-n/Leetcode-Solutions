class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        differences=sorted([(cap-rock) for rock,cap in zip(rocks,capacity)])
        for index,diff in enumerate(differences):
            if additionalRocks>=diff: 
                additionalRocks-=diff
                continue
            return index
        return index+1