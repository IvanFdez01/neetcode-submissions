class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        quadrants = [[0, set()] for _ in range(9)]
        for i in range(9):
            sx = set()
            sy = set()
            numbersx = 0
            numbersy = 0
            for j in range(9):
                x = board[i][j]
                y = board[j][i]
                if x != '.':
                    numbersx += 1
                    sx.add(x)
                    
                    q = self.quadrant(i,j)
                    quadrants[q][0] += 1
                    quadrants[q][1].add(x)

                if y != '.':
                    numbersy += 1
                    sy.add(y)
            if len(sx) != numbersx or len(sy) != numbersy:
                return False
            sx.clear()
            sy.clear()
        
        for i, s in quadrants:
            if i != len(s):
                return False
        return True

    def quadrant(self, i, j):
        return (i // 3) * 3 + (j // 3)    
