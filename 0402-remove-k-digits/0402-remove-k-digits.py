class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        i=0
        n=len(num)
        res=[]
        
        while i<n:
            res.append(num[i])
            
            while k and len(res)>1 and res[-2]>res[-1]:
                res.pop(-2)
                k-=1
            
            i+=1
        while k:
            res.pop()
            k-=1
            
        while len(res)>1 and res[0]=='0':
            res.pop(0)
        return ''.join(res) if res else '0'
                
        
        
        