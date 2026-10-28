class Solution:
    def maxArea(self, h: List[int]) -> int:
        i = 0
        j = len(h) - 1
        maxarea = -1
        while i < j:
            s = self.area(h, i, j)
            maxarea = max(maxarea, s)
            if h[i] < h[j]:
                i += 1
            else:
                j -= 1
        return maxarea

    def area(self, h, i , j):
        l1 = j - i
        l2 = min(h[i], h[j])
        return l1*l2