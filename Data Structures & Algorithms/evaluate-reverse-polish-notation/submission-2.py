
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        ops = set(['+', '*', '-', '/'])
        acum = 0
        for t in tokens:
            # print(stack)
            if t in ops:
                op1 = int(stack.pop())
                op2 = int(stack.pop())
                acum = self.operate(op2, op1, t)
                # print(op1,t,op2, acum)
                stack.append(acum)

            else:
                stack.append(int(t))
        return stack[-1]


    def operate(self, a,b, sign:str) -> int:
        if sign == '+':
            return a + b
        if sign == '-':
            return a - b
        if sign == '*':
            return a * b
        if sign == '/':
            return int(a / b)
            