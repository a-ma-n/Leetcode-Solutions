class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        
        even,odd=0,0
        for i,j in enumerate(position):
            if j%2==0:
                even+=1
            else:
                odd+=1
        return min(even,odd)
                