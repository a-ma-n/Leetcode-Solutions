#User function Template for python3
from functools import lru_cache

class Solution:
    def minimumEnergy(self, height, n):
        # Code here
        if n==2:
            return abs(height[0]-height[1])
        elif n==1:
            return height[0]
        
        # @lru_cache(None)
        # def calculateEnergy(i,cost):
        #     if i==n-2:
        #         return cost+abs(height[i]-height[i+1])
        #     if i==n-3:
        #         return cost+min(abs(height[i]-height[i+1])+abs(height[i+1]-height[i+2]),abs(height[i]-height[i+2]))
        #     else:
        #         return min(calculateEnergy(i+1,cost+abs(height[i]-height[i+1])),calculateEnergy(i+2,cost+abs(height[i]-height[i+2])))
        
        cost=[0]*n
        #cost[0]=height
        cost[1]=abs(height[1]-height[0])
        for i in range(2,n):
            cost[i]=min(cost[i-1]+abs(height[i]-height[i-1]),cost[i-2]+abs(height[i]-height[i-2]))
        
        # print(cost)
        return cost[n-1]
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        height = list(map(int, input().split()))
        ob = Solution()
        print(ob.minimumEnergy(height, n))
# } Driver Code Ends