'''
1. 原题
https://leetcode.com/problems/rotate-image/

2. 思路
给出一个方阵，将其顺时针旋转90度后，输出结果。

限定条件，空间复杂度为常量。

显然，最容易想到的是一圈圈的交换元素旋转。不过代码实现有点复杂。

可以慢慢观察，矩阵先以副对角线交换后，再水平居中翻转，就能实现。

也可以先主对角线，再竖直居中对调。
'''
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for i in range(n): //***swap between sub diagonal
            for j in range(n-i-1):
                matrix[i][j], matrix[n-1-j][n-1-i] = matrix[n-1-j][n-1-i], matrix[i][j]
        for i in range(n//2): //*** swap between horizonal middle line
            for j in range(n):
                matrix[i][j], matrix[n-1-i][j] = matrix[n-1-i][j], matrix[i][j]
            
        
