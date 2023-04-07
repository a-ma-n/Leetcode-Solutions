class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        minD=1e6
        mapper=defaultdict(list)
        for i in range(1,len(arr)):
            diff=(arr[i]-arr[i-1])
            mapper[diff].append([arr[i-1],arr[i]])
            minD=min(minD,diff)
        return mapper[minD]