class Solution:
    def repairCars(self, A: List[int], cars: int) -> int:
        count = Counter(A)
        h = [[a, a, 1, count[a]] for a in count]
        heapify(h)
        while cars > 0:
            time, rank, k, count = heappop(h)
            cars -= count
            k += 1
            heappush(h, [rank * k * k, rank, k, count])
        return time
        