class Solution:
    def reverseParentheses(self, s: str) -> str:
        res = ['']
        for c in s:
            if c == '(':
                res.append('')
            elif c == ')':
                res[len(res)-2] += res.pop()[::-1]
            else:
                res[-1] += c
        return "".join(res)