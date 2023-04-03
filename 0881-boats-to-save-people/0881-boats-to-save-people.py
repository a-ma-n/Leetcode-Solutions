class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        boats=0
        n=len(people)
        
        l,r=0,n-1
        totalWeight=0
        # for i,j in enumerate(people):
        #     if j+people[n-1-i]
        # print(people)
        if len(people)==1: return 1
        while l<=r:
            c=0
            while people[r]+totalWeight<=limit and c<=1:
                c+=1
                totalWeight+=people[r]
                # print('r',r,totalWeight)
                r-=1
            # c=0
            while people[l]+totalWeight<=limit and c<=1:
                c+=1
                totalWeight+=people[l]
                l+=1
            else:
                boats+=1
                totalWeight=0
        if totalWeight!=0:
            boats+=1
        return boats
    
"""
[3,2,2,1]
3
[3,5,3,4]
5
[1]
2
[2]
5
[5,1,4,2]
6
"""