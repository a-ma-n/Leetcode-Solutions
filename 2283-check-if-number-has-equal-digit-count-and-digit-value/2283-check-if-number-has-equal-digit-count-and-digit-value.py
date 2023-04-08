class Solution:
    def digitCount(self, num: str) -> bool:
        c=Counter(list(num))
        # print(c)
        for i in range(len(num)):
            # print(i,c[i],num[i])
            if str(c[str(i)])!=num[i]: 
                return False
        return True