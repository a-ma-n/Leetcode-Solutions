class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        differences=[]
        for rock,cap in zip(rocks,capacity): differences.append(cap-rock)
        differences.sort()
        countOfFilledBags=0
        # print(differences)
        for diff in differences:
            if diff==0: 
                countOfFilledBags+=1
                
            elif additionalRocks<diff: break
            else: 
                countOfFilledBags+=1
                additionalRocks-=diff
            # print(countOfFilledBags,diff)
        return countOfFilledBags