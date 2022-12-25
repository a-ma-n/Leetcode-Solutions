
class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        sortedNums=sorted(nums)
        # build prefix array
        for i in range(1,len(nums)):
            sortedNums[i]=sortedNums[i-1]+sortedNums[i]
        
        ans=[]
        
        # For each query, find its insertion index to the prefix sum array.
        for query in queries:
            index = bisect.bisect_right(sortedNums,query)
            ans.append(index)
        
        return ans