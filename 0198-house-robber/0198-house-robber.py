class Solution:
    def rob(self, nums: List[int]) -> int:
        # second_prev=prev=0
        if not nums:
            return 0
        maxRobbedAmount = [None for _ in range(len(nums) + 1)]
        
        N = len(nums)
        
        # Base case initialization.
        maxRobbedAmount[N], maxRobbedAmount[N - 1] = 0, nums[N - 1]
        
        # DP table calculations.
        for i in range(N - 2, -1, -1):
            
            # Same as recursive solution.
            maxRobbedAmount[i] = max(maxRobbedAmount[i + 1], maxRobbedAmount[i + 2] + nums[i])
            
        return maxRobbedAmount[0]   
            