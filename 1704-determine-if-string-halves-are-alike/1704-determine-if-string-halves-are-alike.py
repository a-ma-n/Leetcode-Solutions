class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        s=s.lower()
        n=len(s)
        vowels="aeiou"
        s1,s2=s[:n//2],s[n//2:]
        c1,c2=0,0
        for i in s1:
            if i in vowels:
                c1+=1
        for j in s2:
            if j in vowels:
                c2+=1
        if c1==c2:
            return True
        return False