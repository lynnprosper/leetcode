/*
1. 原题
https://leetcode.com/problems/longest-palindromic-substring/

2. 思路
题意：找出最长回文子串。方法有多种，暴力破解和动态规划等。这里采用DP算法。

动态规划的核心是找出转移方程。

我们假设i~j是一个回文串，那么若s[i-1] == s[j+1], (i-1, j+1)也是一个回文串，否则不是。

于是，我们设定一个数组d[1000][1000]. d[i][j] = 1表示回文串，0不是。转移方程有了，处理初始条件。

显然，d[i][i]是回文。此外，两个字符也有可能是，这是边界条件之一。

从而，一个循环里，赋值d[i][i], 同时处理两个字符的情况。
*/

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0)
            return "";

        int d[1000][1000] = {0};
        int pos{s.size()-1}, length{1};
        for (int i = 0; i < s.size(); i++) //**处理边界
        {
            d[i][i] = 1;
            if (i < s.size()-1 && s[i] == s[i+1])
            {   d[i][i+1] = 1;
                length = 2;
                pos = i;
            }
        }
        
        for (int len = 3; len <= s.size(); len++) //**长度从3开始
        {
            for (int i = 0; i + len <= s.size(); i++)
            {
                int j = i+len-1;
                if (s[i] == s[j] && d[i+1][j-1] == 1) //*状态转移
                {
                    d[i][j] = 1;
                    length = len;
                    pos = i;
                }
            }
        }
        return s.substr(pos, length);
    }
};
