/*
1. 原题
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

2. 思路
题意：给出一串数，输出 每个数可表示的字符组成的字符串组合。

中等难度。这里采用的迭代算法。即假如有3个字母的数N个，4个字母的数M个（N+M为给定的长度），则

组合总数num=3^N*4^M. 那么，[0, num）依次遍历即可。其中，第i个，可以依次算出当前组合每个字符。

更简单的方法是用递归。
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return vector<string>();
        vector<string> h = {"", "", "abc", "def", "ghi", "jkl",
                           "mno", "pqrs", "tuv", "wxyz"};
        int len = digits.size();
        vector<int> base(len); //存储num要整除的除数
        base[0] = 1; //第一个肯定为1
        for (int i = 1; i < len; i++) //求出除数
            base[i] = base[i-1] * h[(digits[i-1] - '0')].size();
        int num = base[len-1] * h[(digits[len-1] - '0')].size(); //组合总数
        vector<string> res(num);
        for (int i = 0; i < num; i++)
        {
            int p;
            for (int j = 0; j < len; j++)
            {
                p = i / base[j] % h[digits[j] - '0'].size(); //当前位置
                res[i].push_back(h[digits[j]-'0'][p]);
            }
        }
        return res;
    }
};
