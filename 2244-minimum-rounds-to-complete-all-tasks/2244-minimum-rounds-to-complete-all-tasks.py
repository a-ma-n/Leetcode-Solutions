class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        return max(-1,sum((count+2)//3 if count>1 else float('-inf') for count in Counter(tasks).values())) 
    