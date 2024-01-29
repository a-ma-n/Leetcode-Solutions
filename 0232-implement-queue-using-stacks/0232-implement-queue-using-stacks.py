class MyQueue:

    # stack1,stack2 = [],[]
    # fill stack 1, then pop whole of stavk 2 and add stack 1s top element at the bottom then push back everything 
    def __init__(self):
        self.stack1,self.stack2=[],[]
        pass

    def push(self, x: int) -> None:
        while self.stack1: 
            self.stack2.append(self.stack1.pop())
        self.stack1.append(x)
        while self.stack2: 
            self.stack1.append(self.stack2.pop())

    def pop(self) -> int:
        return self.stack1.pop()

    def peek(self) -> int:
        return self.stack1[-1]

    def empty(self) -> bool:
        return len(self.stack1)==0