class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        ans=[]
        temp=intervals[0]
        for it in intervals[1:]:
            if it[0]<=temp[1]:
                temp[1]=max(temp[1],it[1])
            else:
                ans.append(temp)
                temp=it
        ans.append(temp)
        return ans
