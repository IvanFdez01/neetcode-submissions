from typing import List
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:

        n = len(temperatures)
        if n == 1:
            return [0]

        results = [0] * n
        stack = []
        for i in range(n):
            # print(stack)
            temp = temperatures[i]
            while len(stack) > 0 and temp > stack[-1][0]:
                s = stack.pop()
                results[s[1]] = i - s[1]
            stack.append((temp, i))

        return results

            