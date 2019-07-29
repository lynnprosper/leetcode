'''
1. 原题
https://leetcode.com/problems/valid-sudoku/

2. 思路
题意：判断数独是否符合给定的条件。

数据结构用map或set存储，利用它们的性质可快速判断是否重复。

每行和每列容易判断，9个小九宫格不是很容易判断。

关键找出第i个小九宫格时的下标。自己用笔画一画就出来了。

访问第i行j次时， 其应该访问的下标是 A[i/3*3+j/3][i%3*3+j%3]。
'''

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            mp1,mp2,mp3 = {}, {}, {}
            for j in range(9):
                if board[i][j] != '.' : #row
                    if board[i][j] in mp1:
                        return False
                    else:
                        mp1[board[i][j]] = True
                if board[j][i] != '.' : #column
                    if board[j][i] in mp2:
                        return False
                    else:
                        mp2[board[j][i]] = True
                
                row, column = (i//3*3+j//3), (i%3*3+j%3)
                if board[row][column] != '.' :  #sub-box
                    if board[row][column] in mp3:
                        return False
                    else:
                        mp3[board[row][column]] = True
        return True
                
