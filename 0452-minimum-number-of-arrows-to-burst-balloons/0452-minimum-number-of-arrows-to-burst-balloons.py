class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x:x[1])
        first_end,arrows=points[0][1],1
        for point_start,point_end in points:
            if first_end<point_start:
                arrows+=1
                first_end=point_end
        return arrows