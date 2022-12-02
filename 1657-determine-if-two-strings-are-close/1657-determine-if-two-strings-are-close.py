from collections import Counter
class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        a=Counter(word1)
        b=Counter(word2)
        if a == b:
            return True
        elif Counter(a.values())==Counter(b.values()) and set(a.keys())==set(b.keys() ):
            return True
        return False