class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        
        @cache
        def seq(ind1,ind2):
            # if ts1==ts2:
            #     return 0
            if ind1<0:
                return sum(ord(c) for c in s2[:ind2+1])
            if ind2<0:
                return sum(ord(c) for c in s1[:ind1+1])
            
            # print(s1[ind1],s2[ind2],ind1,ind2,ts1,ts2)
            
            if s1[ind1]==s2[ind2]:
                return seq(ind1-1,ind2-1)
            
            # delete
            # newStr1=ts1[:ind1]+ts1[ind1+1:]
            # newStr2=ts2[:ind2]+ts2[ind2+1:]
            
            return min(
                ord(s1[ind1])+
                seq(ind1-1,ind2),
                ord(s2[ind2])+
                seq(ind1,ind2-1)
            )
            
            
                

        return seq(len(s1)-1,len(s2)-1)
            