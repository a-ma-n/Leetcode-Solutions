from functools import cache

class Solution:
    def numberOfWays(self, numPeople: int) -> int:
        @cache
        def dp(num_people):
            if num_people == 0:
                return 1
            return sum(dp(group1) * dp(num_people-2-group1) for group1 in range(0, num_people-1, 2))
        
        return dp(numPeople) % (10**9+7)