class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        low=1
        high=10**7
        
        # if
        is_ontime = lambda s: sum(math.ceil(d / s) for d in dist[:-1]) + dist[-1] / s <= hour
        
        while low<high:
            mid=low+(high-low)//2
            if is_ontime(mid):
                    high = mid
            else:
                    low = mid+1
        return low if is_ontime(low) else -1
        # return -1
    
    # import math
    # class Solution:
    #     def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
    #         is_ontime = lambda s: sum(math.ceil(d / s) for d in dist[:-1]) + dist[-1] / s <= hour
    #         low, high = 0, 10**7
    #         while low + 1 < high:
    #             mid = low + (high - low) // 2
    #             if is_ontime(mid):
    #                 high = mid
    #             else:
    #                 low = mid
    #         return high if is_ontime(high) else -1