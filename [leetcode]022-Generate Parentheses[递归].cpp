/*
1. 原题
https://leetcode.com/problems/generate-parentheses/

2. 思路
题意：给出括号的对数，输出所有有效的括号组合。

中等难度。每一个组合中，任一位置前左括号的出现次数一定大于或等于右括号的次数时才有效。

问题不好下手，想一想，问题可以通过划分成小规模的子问题来降低复杂维度。

于是，递归方法出来了。如何递归呢？

鉴于有效的条件，那么要考虑当前递归时左括号和右括号的个数。这里，我们采用剩余次数来表示。

a1. 左括号剩余个数大于右括号时，无效。

a2. 两者均为0时，一个有效组合。

a3. 剩下的按照个数减一递归。
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n, n, "", res);
        return res;
    }
    
    void dfs(int left, int right, string str, vector<string> &res)
    {
        if (left > right) return;
        else if (left == 0 && right == 0)
            res.push_back(str);
        else
        {
            if (left > 0)
                dfs(left-1, right, str +'(', res);
            if (right > 0)
                dfs(left, right-1, str+')', res);
        }
        return;
    }
};
