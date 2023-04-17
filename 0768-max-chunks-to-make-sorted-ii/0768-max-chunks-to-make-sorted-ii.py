class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        ans = 0
        n = len(arr)
        rightmin = [math.inf]*(n+1)
        currmin = math.inf
        maxele = arr[0]

        # loop from backward of the array to get the minimum element from i to n
        for j in range(n-1, -1, -1):
            if arr[j]<currmin:
                currmin = arr[j]
            rightmin[j] = currmin

        #Forward loop to compare with current max element (maxele) and count the valid partitions
        for i in range(len(arr)):
            if maxele<arr[i]:
                maxele = arr[i]
            if maxele<=rightmin[i+1]:
                ans+=1
        return ans