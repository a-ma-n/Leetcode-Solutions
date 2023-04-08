class Solution:
    def findRestaurant(self, l1: List[str], l2: List[str]) -> List[str]:
        temp=defaultdict(list)
        minv=1e9
        for idx,i in enumerate(l1):
            if i in l2:
                print(idx,l2.index(i),i)
                temp[idx+l2.index(i)].append(i)
                minv=min(minv,idx+l2.index(i))
            # print(temp)
        return sorted(temp[minv])
        
            