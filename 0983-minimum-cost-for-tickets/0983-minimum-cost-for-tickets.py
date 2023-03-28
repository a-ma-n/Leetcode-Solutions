class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        
        n=len(days)
        
        # get the day just out of the range of current nextDays
        def getNewIndex(ind,nextDays):
            for j in range(ind,n):
                if days[j]>days[ind]+nextDays:
                    # print('new Index:',ind,j,nextDays)
                    return j
            return n
        
        @cache
        def getMinCost(ind,depth=0):
            # base cases
            if ind>n-1:
                return 0
            # if ind>n-1:
            #     return 0
            # 1 day ticket
            option1=costs[0]+getMinCost(ind+1,depth+1)
            option7=costs[1]+getMinCost(getNewIndex(ind,6),depth+1)
            option30=costs[2]+getMinCost(getNewIndex(ind,29),depth+1)
            # print('d',depth)
            # if option1<option7 and option1<option30:
            #     # print("1",ind,option1)
            # elif option7<option1 and option7<option30:
            #     # print("7",ind,option7)
            # else:
                # print("30",ind,option30)
            return min(option1,option7,option30)
        
        return getMinCost(0)