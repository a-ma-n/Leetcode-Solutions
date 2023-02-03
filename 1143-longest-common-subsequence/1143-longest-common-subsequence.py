class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n,m=len(text1),len(text2)
        k = max(m,n)
        prev,cur=[0]*(m+1),[0]*(m+1)
        for index1 in range(1,n+1):
            for index2 in range(1,m+1):
                if text1[index1-1]==text2[index2-1]:
                    cur[index2] = 1+prev[index2-1]
                else:
                    cur[index2]=max(prev[index2],cur[index2-1])
            prev=cur.copy()
        print(prev)
        return prev[m]