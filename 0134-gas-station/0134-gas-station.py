from itertools import product
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        maxValue = 1e6
        minValue = -1
        total = 0
        for index, (gasValue, costValue) in enumerate(zip(gas, cost)):
            total += gasValue - costValue
            if total < maxValue:
                maxValue = total
                minValue = index
        if total < 0:
            return -1
        return (minValue + 1) % len(gas)
                