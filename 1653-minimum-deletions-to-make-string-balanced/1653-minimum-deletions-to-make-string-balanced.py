class Solution:
    def minimumDeletions(self, s: str) -> int:
        deletions=0
        stack=[]
        for c in s:
            if c=="a":
                if stack:
                    stack.pop()
                    deletions+=1
            else: stack.append(c)
                
        return deletions