class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) == 1:
            return False

        stack = [] + [s[0]]
        for ch in s[1:]:
            
            if len(stack) > 0 and stack[-1] == self.opposite(ch):
                stack.pop()
            else:
                stack.append(ch)

            
        return len(stack) == 0


    def opposite(self, ch):
        if ch == ']':
            return '['
        elif ch == '}':
            return '{'
        elif ch == ')':
            return '('
        else:
            return '.'