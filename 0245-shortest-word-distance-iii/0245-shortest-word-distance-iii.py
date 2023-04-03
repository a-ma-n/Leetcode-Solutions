class Solution:
    def shortestWordDistance(self, wordsDict: List[str], word1: str, word2: str) -> int:
        w1=-1
        w2=-1
        minDist=len(wordsDict)
        
        for i,j in enumerate(wordsDict):
            if j==word1:
                w1=i
                if w2!=-1:
                    minDist=min(minDist,w1-w2)
                    
            if j==word2:
                w2=i
                if w1!=-1 and w1!=w2:
                    minDist=min(minDist,w2-w1)
                    
        return minDist
        