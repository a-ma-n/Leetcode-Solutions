class Solution:
    def isValid(self, string: str) -> bool:
        s=[]
        for i in string:
            if i in ["(","{","["]:
                s.append(i)
            elif s and s[-1]=="(" and i==")":
                s.pop()
            elif s and s[-1]=="{" and i=="}":
                s.pop()
            elif s and s[-1]=="[" and i=="]":
                s.pop()
            else:
                return False
        if s: return False
        return True