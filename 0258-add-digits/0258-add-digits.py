class Solution:
    def addDigits(self, d: int) -> int:
        while len(str(d))>1:
            # print(d)
            d=sum(map(int,list(str(d))))
        return d