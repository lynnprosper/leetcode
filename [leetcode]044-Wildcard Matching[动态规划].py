'''
1. 原题
https://leetcode.com/problems/wildcard-matching/

2. 思路
题意：判断模式串和目标串是否匹配

解法有多种，可以用递归。

我最初写的递归，不过会超时。字符串匹配问题通用方法是动态规划。

数组dp[i][j]表示p[i]之前的字符串是否匹配s[j]之前的字符串。

边界dp[0][0]=1，显然目标串作为内循环方便。
'''
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        s_len, p_len=len(s)+1, len(p)+1 #plus 1 : range in 1~n
        dp = [[0]*s_len for i in range(p_len)] #dp[i][j] means whether p[i] matches s[j]
        dp[0][0] = 1
        for i in range(1, p_len):
            dp[i][0] = (p[i-1]=='*' and dp[i-1][0])
            for j in range(1, s_len):
                if p[i-1] == '?':
                    dp[i][j] = dp[i-1][j-1]
                elif p[i-1] == '*':
                    dp[i][j] = dp[i-1][j] or dp[i][j-1]
                else:
                    dp[i][j] = dp[i-1][j-1] if p[i-1]==s[j-1] else 0
                    
        return dp[len(p)][len(s)]
