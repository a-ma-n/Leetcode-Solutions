class Solution:
    def rob(self, nums: List[int]) -> int:
        second_prev=prev=0
        for n in nums:
            second_prev,prev=prev,max(n+second_prev,prev)
        return prev
            