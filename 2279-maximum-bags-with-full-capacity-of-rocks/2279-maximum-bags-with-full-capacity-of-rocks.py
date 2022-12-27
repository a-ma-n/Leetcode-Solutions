class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        differences=[]
        for rock,cap in zip(rocks,capacity): differences.append(cap-rock)
        differences.sort()
        countOfFilledBags=0
        for index,diff in enumerate(differences):
            if additionalRocks<diff: return index
            elif diff!=0: 
                additionalRocks-=diff
            countOfFilledBags+=1
        return index+1