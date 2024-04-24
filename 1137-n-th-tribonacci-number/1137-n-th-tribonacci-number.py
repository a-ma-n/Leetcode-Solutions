class Solution:
    def tribonacci(self, n: int) -> int:
        a,b,c=0,1,1
        if n==0: return 0
        elif n==1: return 1
        elif n==2: return 1
        else:
            n-=2
            while(n>0):
                d=a+b+c
                a=b
                b=c
                c=d
                n-=1
        return d
        