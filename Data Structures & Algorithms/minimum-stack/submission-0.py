class MinStack:

    def __init__(self):
        self.main = []
        self.aux = []

    def push(self, val: int) -> None:
        self.main.append(val)
        self.aux.append(min(val, self.aux[-1]) if len(self.aux) > 0 else val)

    def pop(self) -> None:
        self.main.pop()
        self.aux.pop()

    def top(self) -> int:
        return self.main[-1] if len(self.main) > 0 else -1

    def getMin(self) -> int:
        return self.aux[-1] if len(self.aux) > 0 else -1 
