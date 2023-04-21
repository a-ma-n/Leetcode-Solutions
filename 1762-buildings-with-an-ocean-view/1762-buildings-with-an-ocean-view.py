class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        oceanBuildings=deque()
        # if len(heights)==1: return [0]
        maxRight=heights[-1]
        oceanBuildings.appendleft(len(heights)-1)
        for i in range(len(heights)-2,-1,-1):
            if maxRight<heights[i]:
                oceanBuildings.appendleft(i)
            maxRight=max(maxRight,heights[i])
        return oceanBuildings