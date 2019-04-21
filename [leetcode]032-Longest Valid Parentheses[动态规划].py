'''
1. 原题
https://leetcode.com/problems/longest-valid-parentheses/submissions/

2. 思路
题意：给出一串由括号组成的字符串，求出最长匹配的子串

思路：比较难。容易想到的方法就是遍历字符串。利用栈的思想，找出匹配的括号位置，

不断更新匹配长度。

另外的方法就是动态规划了。dp[i]表示以下标i结尾时的最长长度。

假如当前位置i，若s[i] = '(', 显然dp[i]= 0;

若s[i] = ')', 我们要看看i-dp[i-1]-1处是不是'(', 不是说明不匹配，dp[i]= 0;

否则，匹配。注意：判断的位置不是i-1, 而是i-dp[i-1]-1。 因为可能存在'(()'这种情况。

匹配成功，dp[i] = dp[i-1]+2。 不过没完，dp[i]还要加上dp[i-dp[i]].

因为之前的长度被'('中断了，还要补上。
'''

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        dp = [0] * len(s) #初始值都是0
        res = 0
        for i in range(1, len(s)):
            if s[i] == ')' and i-1 >= dp[i-1] and s[i-dp[i-1]-1] == '(':
                dp[i] = dp[i-1]+2 #匹配成功
                if i >= dp[i]:
                    dp[i] += dp[i-dp[i]] #还要加上之前的
            res = max(res, dp[i])
        return res
            
