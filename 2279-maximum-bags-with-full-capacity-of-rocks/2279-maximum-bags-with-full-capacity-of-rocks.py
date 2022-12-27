class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        differences=[]
        for rock,cap in zip(rocks,capacity): differences.append(cap-rock)
        differences.sort()
        countOfFilledBags=0
        # print(differences)
        for diff in differences:
            if additionalRocks<diff: break
            elif diff!=0: 
                additionalRocks-=diff
            countOfFilledBags+=1
                
            # else: 
            #     countOfFilledBags+=1
                
            # print(countOfFilledBags,diff)
        return countOfFilledBags