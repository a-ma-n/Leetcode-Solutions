class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        
        i,j,ml,n=0,1,0,len(s)
        if(n==1):
            return 1
        while(i<n and j<n):
            w=s[i:j+1]
            unique=set(w)
            while (len(unique)>2):
                i+=1
                w=s[i:j+1]
                unique=set(w)
            ml=max(ml,j-i+1)
            
            j+=1
        return ml
            