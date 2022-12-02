from collections import Counter
class Solution:
    def closeStrings(self, *args) -> bool:
        c1,c2=map(Counter,args)
        if Counter(c1.values())==Counter(c2.values()) and set(c1.keys())==set(c2.keys() ):
            return True
        return False