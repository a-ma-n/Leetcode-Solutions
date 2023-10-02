class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        bob,alice=0,0
        for i in range(1,len(colors)-1):
            if colors[i-1]==colors[i] and colors[i]==colors[i+1]:
                if colors[i]=='A':
                    alice+=1
                else:
                    bob+=1
        return alice>bob
