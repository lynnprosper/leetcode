'''
1. 原题
https://leetcode.com/problems/count-and-say/

2. 思路
题意不是很好懂。题目说的是，给定n，输出上一次可以读出的字符串。

默认n=1，字符串‘1’， 那么n=2， 上一次是一个1， 所以输出'11'。

又比如 n=4, 对应字符串‘1211’， 那么n=5, 上一次里有一个1，一个2， 两个1， 所以输出'111221'

显然，用递归解决即可。

已AC
'''

class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return '1'
        last_str = self.countAndSay(n-1)
        ch, cnt, res = '', 0, ''
        for cur in last_str:
            if ch != cur:
                if cnt > 0:
                    res += str(cnt) + ch
                ch = cur
                cnt = 1
            else:
                cnt += 1
        if cnt > 0:
            res += str(cnt) + ch
        return res
