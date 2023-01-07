class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        totalSurplus, surplus, start =  0, 0, 0
        for i in range(len(gas)):
            totalSurplus += gas[i] - cost[i]
            surplus += gas[i] - cost[i]
            if surplus < 0:
                surplus = 0
                start = i + 1
        return -1 if (totalSurplus < 0) else start
