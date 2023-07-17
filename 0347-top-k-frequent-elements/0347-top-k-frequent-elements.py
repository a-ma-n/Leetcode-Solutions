from collections import Counter
import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        return [ i for i,c in Counter(nums).most_common(k)]
        # cnt=Counter(nums)
        # return heapq.nlargest(k,cnt,key=lambda x:cnt[x])
