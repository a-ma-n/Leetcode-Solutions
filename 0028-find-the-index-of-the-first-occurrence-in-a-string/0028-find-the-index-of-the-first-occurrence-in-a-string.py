class Solution:
    def strStr(self, h: str, n: str) -> int:
        for i,a in enumerate(h):
            for j,b in enumerate(n):
                if a==b:
                    cnt=0
                    ind=i
                    while i<len(h) and j<len(n) and h[i]==n[j]:
                        i+=1
                        j+=1
                        cnt+=1
                    # print(a,b,cnt)
                    if cnt==len(n):
                        return ind
        return -1