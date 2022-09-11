"""
- descending sort on the efficiences, take all the candidates before the 1st candidate
- sort based on the speeds of the engineers and take the fastest engineers



"""
class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        modulo = 10 ** 9 + 7

        # build tuples of (efficiency, speed)
        candidates = zip(efficiency, speed)
        # sort the candidates by their efficiencies - in descending order
        candidates = sorted(candidates, key=lambda t:t[0], reverse=True)

        speed_heap = []
        speed_sum, perf = 0, 0
        for curr_efficiency, curr_speed in candidates:
            # maintain a heap for the fastest (k-1) speeds
            # pop the element with the min speed if oversized & subtract the same from the speed sum
            if len(speed_heap) > k-1:
                speed_sum -= heapq.heappop(speed_heap)
            # push the speed into the heap
            heapq.heappush(speed_heap, curr_speed)

            # calculate the maximum performance with the current member as the least efficient one in the team
            speed_sum += curr_speed
            # store the max preformance encountered till now
            perf = max(perf, speed_sum * curr_efficiency)
        #return the modulo of the ans as given in q
        return perf % modulo