class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        set = start^goal
        c=0
        while(set):
            c+=set&1
            set>>=1
        return c
        