class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        # expand into. intervals and then merge and give sum
        intervals=[]
        for i in timeSeries:
            intervals.append([i,i+duration])
        
        intervals.sort()
        temp=intervals[0]
        ans=[]
        # end=intervals[0][1]
        for i in intervals[1:]:
            if i[0]<=temp[1]:
                temp[1]=max(temp[1],i[1])
            else:
                ans.append(temp)
                temp=i
        ans.append(temp)
        diff=0
        for i,j in ans:
            diff+=j-i
        return diff