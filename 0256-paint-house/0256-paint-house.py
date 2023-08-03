class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        
        @cache
        def recur(ind,lastVal):
            if ind<0:
                return 0
            
            red=blue=green=1e9
            
            
            # if lastVal=="temp":
            red=costs[ind][0]+recur(ind-1,"red")
            blue=costs[ind][1]+recur(ind-1,"blue")
            green=costs[ind][2]+recur(ind-1,"green")
                # print(red,blue,green,costs[ind][0],costs[ind][1],costs[ind][2])
                # return min(red,blue,green)
            
            if lastVal=="red":
                # print(ind,"red",costs[ind][0])
                # red=costs[ind][0]+recur(ind-1,"red")
                return min(blue,green)
            elif lastVal=="blue":
                # print(ind,"blue",costs[ind][1])
                # blue=costs[ind][1]+recur(ind-1,"blue")
                 return min(red,green)
            elif lastVal=="green": 
                # print(ind,"green",costs[ind][2])
                # green=costs[ind][2]+recur(ind-1,"green")
                return min(blue,red)
            else:
                return min(red,blue,green)
            
        return recur(len(costs)-1,"temp")