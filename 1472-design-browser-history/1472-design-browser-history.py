class BrowserHistory:
    history=[]
    # totalSitesVisited=0
    currentIndex=0
    
    def __init__(self, homepage: str):
        self.history=[]
        self.currentIndex=0
        self.history.append(homepage)
        # self.totalSitesVisited+=1
        self.currentIndex=len(self.history)-1

    def visit(self, url: str) -> None:
        # print(self.history,self.currentIndex)
        #clear history curindex+1 onwards
        
        self.history=self.history[:self.currentIndex+1].copy()
        # print(self.history,self.currentIndex)
        self.history.append(url)
        self.currentIndex=len(self.history)-1

    def back(self, steps: int) -> str:

        if self.currentIndex-steps<0: 
            self.currentIndex=0
            # print(self.history,self.currentIndex,steps,self.history[self.currentIndex])
            return self.history[0]
        self.currentIndex-=steps
        # print(self.history,self.currentIndex,steps,self.history[self.currentIndex])
        return self.history[self.currentIndex]
        

    def forward(self, steps: int) -> str:
        if steps+self.currentIndex>=len(self.history):
            self.currentIndex=len(self.history)-1
            return self.history[-1]
        # print(self.history,self.currentIndex,steps)

        self.currentIndex+=steps
        return self.history[self.currentIndex]
        


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)