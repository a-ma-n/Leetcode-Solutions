class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        boats=0
        n=len(people)
        
        l,r=0,n-1
        totalWeight=0

        if len(people)==1: return 1
        while l<=r:
            countOfPeople=0
            while people[r]+totalWeight<=limit and countOfPeople<=1:
                totalWeight+=people[r]
                r-=1
                countOfPeople+=1
            while people[l]+totalWeight<=limit and countOfPeople<=1:
                totalWeight+=people[l]
                l+=1
                countOfPeople+=1
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