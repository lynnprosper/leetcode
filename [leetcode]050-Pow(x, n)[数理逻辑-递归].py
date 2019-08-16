'''
1. 原题
https://leetcode.com/problems/powx-n/

2. 思路
题意，求一个数的n次方。

把n次方分半，看成求两个n/2次方。即用递归求解。
'''

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if (n==0):
            return 1
        if (n==1):
            return x
        
        res = self.myPow(x*x, abs(n)//2) //***use recursion to process sub_problem
        if (abs(n)%2 == 1):
            res = res*x
        if n < 0:
            return 1/res
        else:
            return res
