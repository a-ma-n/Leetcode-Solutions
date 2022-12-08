# explanation: https://leetcode.com/problems/split-message-based-on-limit/discuss/2807165/Brute-Force-oror-Simple-Approach-oror-C%2B%2B-oror-Explained
# code: https://leetcode.com/problems/split-message-based-on-limit/discuss/2807165/Brute-Force-oror-Simple-Approach-oror-C%2B%2B-oror-Explained

class Solution:
    def splitMessage(self, message: str, limit: int) -> List[str]:
        dig,cum_sum=[0]*10001,[0]*10001
        ret=0
        
        for i in range(1,10001):
            dig[i] = len(str(i)) 
            cum_sum[i] = cum_sum[i-1]+dig[i]
        
        actual_size = len(message)
        ret=[]
        print("actual size:",actual_size)
        for N in range(1,actual_size+1):
            newSize=actual_size+3*N+dig[N]*N+cum_sum[N]
            print("limit:",newSize)

            if ((newSize+limit-1)//limit==N):
                print("in",N)
                s=""
                cur = 1

                extra = dig[N]+3
                for c in message:
                    s+=c
                    if len(s)+dig[cur]+extra==limit:
                        s+="<"+str(cur)+"/"+str(N)+">"
                        ret.append(s)
                        s=""
                        cur+=1
                print("s is:",s)
                if len(s):
                        s+="<"+str(cur)+"/"+str(N)+">"
                        ret.append(s)
                        s=""
                return ret
        return ret
                
            