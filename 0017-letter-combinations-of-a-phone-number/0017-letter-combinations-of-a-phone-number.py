class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        numberMap={2:"abc",3:"def",4:"ghi",5:"jkl",6:"mno",7:"pqrs",8:"tuv",9:"wxyz"}
        n=len(digits)
        self.ans=[]
        def recur(ind,temp):
            if ind==n:
                self.ans.append(temp)
                return
            letters=numberMap[int(digits[ind])]
            for l in letters:
                # temp+=l
                recur(ind+1,temp+l)
                # temp
            return
        
        recur(0,"")
        if len(self.ans)==1 and self.ans[0]=="": return []
        return self.ans