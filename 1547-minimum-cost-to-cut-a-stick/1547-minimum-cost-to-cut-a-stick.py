# we need to sort the cuts array , if say on the right partition we get qan element smaller it will be dependent on the lft partition, and we do not want that to happen thus we will sort it initially
from functools import cache
class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        @cache
        def f(i,j):
            if i>j : return 0
            mini=1e9
            for ind in range(i,j+1):
                cost=cuts[j+1]-cuts[i-1]+f(i,ind-1)+f(ind+1,j)
                mini=min(mini,cost)
            return mini
        cuts.insert(0,0)
        cuts.append(n)
        cuts.sort()
        print(cuts)
        return f(1,len(cuts)-2)