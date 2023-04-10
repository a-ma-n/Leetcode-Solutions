class Solution:
    def removeVowels(self, s: str) -> str:
        ans=""
        v="aeiou"
        for i in s:
            if i not in v:
                ans+=i
        return ans
                