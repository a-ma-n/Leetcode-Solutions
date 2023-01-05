class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        temp=points[0][1]
        countOfArrows=1
        for point in points:
            if point[0]<=temp:
                temp=min(point[1],temp)
            else:
                countOfArrows+=1
                temp=point[1]
        return countOfArrows