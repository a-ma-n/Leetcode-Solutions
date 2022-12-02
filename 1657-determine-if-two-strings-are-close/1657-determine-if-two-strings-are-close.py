from collections import Counter
class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        c1=Counter(word1)
        c2=Counter(word2)
        if c1==c2 or Counter(c1.values())==Counter(c2.values()) and set(c1.keys())==set(c2.keys() ):
            return True
        return False