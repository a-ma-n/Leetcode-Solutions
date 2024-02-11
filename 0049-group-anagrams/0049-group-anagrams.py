from collections import defaultdict,Counter
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans=collections.defaultdict(list)
        for i in strs:
            count = [0] * 26
            for c in i:
                count[ord(c) - ord('a')] += 1
            ans[tuple(count)].append(i)
        return ans.values()