class Solution:
    def concatenatedBinary(self, n: int) -> int:
        ans=""
        for i in range(1,n+1):
            ans+=str(bin(i))[2:]
        ans='0b'+ans
        # print(ans)

        return int(ans,2)%(10**9+7)