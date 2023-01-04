from collections import Counter
class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        rounds=0
        print(Counter(tasks).items())
        for element,count in Counter(tasks).items():
            if count==1: return -1
            elif count%3==0: rounds+=count//3
            elif count%3==1: rounds+=count//3+1 # count//3-1 3s and 2 2s
            elif count%3==2: rounds+=count//3+1
            elif count%2==0 or count%2==1: rounds+=count//2
            
            # elif : rounds+=count//2
            # elif count%3==: rounds+=count//3
        return rounds