class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        
        one_min_angle=6 # 60min->360
        one_hour_angle=30 # 360 degree/12=30 degree
        
        minutes_angle = one_min_angle*minutes
        hour_angle = (hour%12 + minutes/60) * one_hour_angle
        
        diff = abs(hour_angle-minutes_angle)
        return min(diff,360-diff)