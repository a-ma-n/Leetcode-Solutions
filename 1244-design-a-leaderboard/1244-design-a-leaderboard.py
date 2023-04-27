class Leaderboard:
    def __init__(self):
        self.scores={}

    def addScore(self, playerId: int, score: int) -> None:
        if playerId not in self.scores:
            self.scores[playerId]=0
        self.scores[playerId]+=score

    def top(self, K: int) -> int:
        
        # try:
        heap = list(self.scores.values())
        print(heap)
        # heapify(heap)
        # # except:
        # print()
        return sum(nlargest(K,heap))
    
    def reset(self, playerId: int) -> None:
        self.scores[playerId] = 0