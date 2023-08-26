class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        pattern = re.compile(r'^(.+)\1+$')
        return pattern.match(s)