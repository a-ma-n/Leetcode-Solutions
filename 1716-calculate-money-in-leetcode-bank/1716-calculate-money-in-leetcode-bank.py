class Solution:
    def totalMoney(self, n: int) -> int:
        # 1 2 3 4 5 6 7 ; i%7==1 sum+=prevMon+1; prevmon=prevMon+1; else
        prevmonday,prevday,ans=0,0,0
        for i in range(1,n+1):
            if i%7==1:
                prevmonday+=1
                ans+=prevmonday
                prevday=0
            else:
                if prevday==0:
                    prevday=prevmonday+1
                else:
                    prevday+=1
                ans+=prevday
        return ans
            