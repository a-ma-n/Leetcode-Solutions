class Solution:
    def countLetters(self, s: str) -> int:
        s=' '+s+' '
        total,count=0,1
        
        for i in range(1,len(s)-1):
            if s[i]!=s[i-1]:
                count=1
            else:
                count+=1
            total+=count
        return total
       