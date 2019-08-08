/*
1. 原题
https://leetcode.com/problems/regular-expression-matching/

2. 思路
题意：按照给定的规则判断两个字符串是否匹配。题目有些难。

常规思路无法很好的处理。经分析，模式串与目标串的匹配可以层层分解成

子模式串与子目标串的匹配。于是，解决这类问题，可以用递归和动态规划。

递归容易理解，这里用的递归。

先处理递归边界。

a1) p为空串时，s空则真，否则false；

a2) p长度1时，p=s或者p="."为true;

下面处理自问题：

显然子问题和'*'的处理有关。

b1) p[1] != '*'. 

    此时若两字符串第一个相等或p[0] = '.'， 那么返回子问题(s.substr(1), p.substr(1))的结果。

    否则false.

b2) p[1] = '*'.

    由于'*'的特殊性，这里要分情况。

    c1) 两字符串第一个字符匹配。那么要循环处理。

         假设'*'重复字符次数0， 处理子问题(s, p.substr(2))。否则重复多次， s取s.substr(1)循环处理。

    c2) 两字符串第一个字符不匹配。处理子问题(s, p.substr(2))。
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        //**边界条件
        if (p.empty())
            return s.empty();
        if (p.size() == 1)
            return (s.size() == 1 && (s == p || p[0] == '.'));
        //子问题递归
        if (p[1] != '*')
        {
            if (s.empty())
                return false;
            return ((s[0] == p[0] || p[0] == '.')
                   && isMatch(s.substr(1), p.substr(1)));
        }
        else
        {
            while (!s.empty() && (s[0] == p[0] || p[0] == '.')) //*的特殊性，处理0~n cases
            {
                if (isMatch(s, p.substr(2)))
                    return true;
                s = s.substr(1);
            }
            return isMatch(s, p.substr(2)); // not match, process next pattern
        }
    }
};
