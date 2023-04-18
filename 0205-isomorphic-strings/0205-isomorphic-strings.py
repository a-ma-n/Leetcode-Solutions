class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
         return list(map(s.find, s)) == list(map(t.find, t))