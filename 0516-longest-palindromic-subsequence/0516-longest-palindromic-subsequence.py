class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        # find lcsubstring b/w s and reverse(s)
        text1,text2=s,s[::-1]
        def lcs(text1,text2):
            l1,l2=len(text1),len(text2)
            prev=[0]*(l2+1)
            cur=[0]*(l2+1)
            for ind1 in range(1,l1+1):
                for ind2 in range(1,l2+1):
                    if text1[ind1-1]==text2[ind2-1]:
                        cur[ind2]=1+prev[ind2-1]
                    else:
                        cur[ind2]=max(cur[ind2-1],prev [ind2])
                prev = cur.copy()
            return prev[l2]
        
        print(s,s[::-1])
        return lcs(s,s[::-1])