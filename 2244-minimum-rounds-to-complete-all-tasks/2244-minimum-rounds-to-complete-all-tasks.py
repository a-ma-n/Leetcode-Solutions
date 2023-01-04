from collections import Counter
class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        counter=Counter(tasks).values()
        return sum(count//3 + int(count%3!=0) for count in counter ) if 1 not in counter else -1
        
        # for count in Counter(tasks).values():
        #     if count==1: return -1
        #     elif count%3==0: rounds+=count//3
        #     else: rounds+=count//3+1 
        # return rounds