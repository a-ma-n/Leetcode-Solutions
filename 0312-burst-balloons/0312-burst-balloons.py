from functools import cache
class Solution:
    #start by taking the last guy
    # we cannot individually solve these problems from top to bottom approach
    #add 1s on each end
    
    def maxCoins(self, a: List[int]) -> int:
        @cache
        def f(i,j):
            if i>j: return 0
            maxi=-float(inf)
            for ind in range(i,j+1):
                cost=a[i-1]*a[ind]*a[j+1]+f(i,ind-1)+f(ind+1,j)
                maxi=max(maxi,cost)
            return maxi
        n=len(a)
        a.insert(0,1)
        a.append(1)
        print(a)
        return f(1,n)