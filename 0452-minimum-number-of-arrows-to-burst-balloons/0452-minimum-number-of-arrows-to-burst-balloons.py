class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        print(points)
        temp=1e9
        countOfArrows=1
        for point in points:
            if temp==1e9:
                temp=point[1]
            else:
                if point[0]<=temp:
                    print(point)
                    temp=min(point[1],temp)
                    continue
                else:
                    print(point)
                    countOfArrows+=1
                    temp=point[1]
        return countOfArrows