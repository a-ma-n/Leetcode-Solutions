class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def valid(A):
            bal=0
            for c in A:
                if c=='(': bal+=1
                else: bal-=1
                if bal<0: return False
            return bal==0
            
        def generate(A=[]):
            if(len(A)==2*n) :
                if valid(A):
                    ans.append("".join(A))
            else:
                A.append('(')
                generate(A)
                A.pop()
                A.append(')')
                generate(A)
                A.pop()
        ans=[]
        generate()
        return ans    