class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        differences=[]
        for rock,cap in zip(rocks,capacity): differences.append(cap-rock)
        differences.sort()
        for index,diff in enumerate(differences):
            if additionalRocks<diff: return index
            if diff!=0: additionalRocks-=diff
        return index+1