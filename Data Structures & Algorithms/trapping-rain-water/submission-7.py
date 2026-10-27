from typing import List
from collections import deque

class Solution:
    def trap(self, h: List[int]) -> int:
        if len(h) < 2:
            return 0

        hayalto = deque()
        hayalto.appendleft(-1)
        alto = len(h) - 1
        for i in range(len(h) - 2, -1, -1):
            if h[alto] >= h[i]:
                hayalto.appendleft(alto)
            else:
                alto = i
                hayalto.appendleft(-1)
        altoder = list(hayalto)

        hayalto = []
        hayalto.append(-1)
        alto = 0
        for i in range(1, len(h) ):
            if h[alto] >= h[i]:
                hayalto.append(alto)
            else:
                alto = i
                hayalto.append(-1)
        altoizq = list(hayalto)
        
        # print(len(h))
        # print(altoizq)
        # print(altoder)
        
        i = 0
        w = 0

        while i < len(h):
            i += 1
            if altoizq[i] != -1:
                break
            
        while i < len(h):
            if altoizq[i] > -1 and altoder[i] > -1:
                # print(i, min(h[altoizq[i]], h[altoder[i]]))
                w += min(h[altoizq[i]], h[altoder[i]]) - h[i]
            
            i += 1
            
            
        return w
            
        