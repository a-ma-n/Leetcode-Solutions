class Solution:
    def myPow(self, x: float, n: int) -> float:
        temp=1
        neg=n<0
        if n==0:return 1 
        if neg:
            n=-n
        while n>0:
            if n%2==0:
                
                x*=x
                # if n==2:n==1
                n/=2
            else:
                if n==1: 
                    x*=temp
                    n-=1
                else:
                    temp*=x
                    n-=1
            # print(x,n,temp)
        if neg: return 1/x
        return x