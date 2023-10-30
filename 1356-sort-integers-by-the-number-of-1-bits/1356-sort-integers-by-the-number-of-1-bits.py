class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        l=[]
        d=dict()
        for i in sorted(arr):
            print(bin(i))
            l.append([bin(i)[2:].count('1'),i])
        s=list(sorted(l ))
        return([ i[1] for i in s])
            